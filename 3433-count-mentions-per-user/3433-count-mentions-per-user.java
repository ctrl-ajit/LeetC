class Solution {
    private int[] offline_until;  

    public int[] countMentions(int number_of_users, List<List<String>> events) {
        int[] mentions = new int[number_of_users];
        offline_until = new int[number_of_users]; 
        
        events.sort((a, b) -> {
            int timeA = Integer.parseInt(a.get(1));
            int timeB = Integer.parseInt(b.get(1));
            if (timeA != timeB) {
                return Integer.compare(timeA, timeB);
            }
  
            String typeA = a.get(0);
            String typeB = b.get(0);
            if (typeA.equals("OFFLINE") && typeB.equals("MESSAGE")) {
                return -1;
            } else if (typeA.equals("MESSAGE") && typeB.equals("OFFLINE")) {
                return 1;
            }
            return 0;
        });

        int i = 0;
        while (i < events.size()) {
            int curr_time = Integer.parseInt(events.get(i).get(1));

            update_statuses(curr_time);
        
            while (i < events.size() && 
                   Integer.parseInt(events.get(i).get(1)) == curr_time &&
                   events.get(i).get(0).equals("OFFLINE")) {
                int user_id = Integer.parseInt(events.get(i).get(2));
                set_offline(user_id, curr_time + 60);
                i++;
            }

            while (i < events.size() && 
                   Integer.parseInt(events.get(i).get(1)) == curr_time &&
                   events.get(i).get(0).equals("MESSAGE")) {
                String variant = events.get(i).get(2);

                if (variant.equals("ALL")) {
                    for (int id = 0; id < number_of_users; id++) {
                        mentions[id]++;
                    }
                } 
                else if (variant.equals("HERE")) {
                    for (int id = 0; id < number_of_users; id++) {
                        if (is_online(id, curr_time)) {
                            mentions[id]++;
                        }
                    }
                } else {
                    String[] parts = variant.split(" ");
                    for (String part : parts) {
                        int userId = Integer.parseInt(part.substring(2));
                        mentions[userId]++;
                    }
                }
                i++;
            }
        }

        return mentions;
    }

    private void update_statuses(int timestamp) {
        for (int i = 0; i < offline_until.length; i++) {
            if (offline_until[i] != 0 && offline_until[i] <= timestamp) {
                offline_until[i] = 0; 
            }
        }
    }

    private boolean is_online(int user_id, int timestamp) {
        return offline_until[user_id] == 0 || offline_until[user_id] <= timestamp;
    }

    private void set_offline(int user_id, int offline_until_time) {
        offline_until[user_id] = offline_until_time;
    }
}