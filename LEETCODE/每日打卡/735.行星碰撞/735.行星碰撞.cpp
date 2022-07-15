class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> sim;
        int size = asteroids.size(), i;
        sim.push_back(asteroids[0]);
        for (i = 1; i <= size - 1; i++)
        {
            int flag = true;//±êÖ¾ÊÇ·ñÅö×²
            if (sim.empty() == 0 && sim.back() > 0 && asteroids[i] < 0)
            {
                
                while (sim.empty() == 0 && sim.back() > 0)
                {
                    if (-asteroids[i] > sim.back())
                    {
                        sim.pop_back();
                    }
                    else if (-asteroids[i] == sim.back())
                    {
                        sim.pop_back();
                        flag = false;
                        break;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag)
            {
                sim.push_back(asteroids[i]);
            }
        }
        return sim;
    }
};
