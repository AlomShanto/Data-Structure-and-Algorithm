#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int number_of_offers;

    cin >> number_of_offers;

    map< string, int > list_of_cities;
    map< string, vector< pair<int, int> > >offer_list_for_cities, cost_for_cities;

    for(int count = 1; count <= number_of_offers; count++)
    {
        string city;
        int maximum_days, cost_per_day;

        cin>>city>>maximum_days>>cost_per_day;

        list_of_cities[city] += maximum_days;

        offer_list_for_cities[city].push_back({cost_per_day,maximum_days});
    }

    map< string, vector< pair<int, int> > >:: iterator it;

    for(it = offer_list_for_cities.begin(); it != offer_list_for_cities.end(); it++)
    {
        sort(it->second.begin(),it->second.end());

        int total_sum=0,total_days=0;

        for(int index = 0; index < it->second.size(); index++)
        {
            pair< int , int>current;


            current.first = total_sum + it->second[index].first * it->second[index].second;
            total_sum = current.first;

            current.second = total_days + it->second[index].second;
            total_days = current.second;


            cost_for_cities[it->first].push_back(current);
        }
    }

    vector< pair<int, string> > ascending_cities_by_per_days;

    map< string, int >:: iterator list_it;

    for(list_it = list_of_cities.begin(); list_it != list_of_cities.end(); list_it++)
    {
        ascending_cities_by_per_days.push_back({list_it->second,list_it->first});
    }

    sort(ascending_cities_by_per_days.begin(),ascending_cities_by_per_days.end());

    int ans_max_day=0;

    for(int index = 0; index < ascending_cities_by_per_days.size(); index++)
    {
        int current = ascending_cities_by_per_days[index].first * (ascending_cities_by_per_days.size()-index);
        //cout<< ans_max_day << " " <<current<<" "<<index<<" "<<ascending_cities_by_per_days[index].first<<" "<<ascending_cities_by_per_days.size()-index<<endl;
        ans_max_day = max(ans_max_day, current);
    }

    long long ans_max_cost=1e18;
    for(int index = 0; index < ascending_cities_by_per_days.size(); index++)
    {
        int current = ascending_cities_by_per_days[index].first * (ascending_cities_by_per_days.size()-index);

        if(current==ans_max_day)
        {

            long long current_cost = 0;
            int req = ascending_cities_by_per_days[index].first;
            for(int super_index = index; super_index < ascending_cities_by_per_days.size(); super_index++)
            {
                string current_city = ascending_cities_by_per_days[super_index].second;

                vector<pair<int,int>> temp;
                temp = cost_for_cities[current_city];

                int low = 0, high = temp.size()-1, last_ok = -1;

                while(low <= high)
                {
                    int mid = (low+high)/2;

                    if(temp[mid].second > req)
                    {
                        high = mid - 1;
                    }
                    else
                    {
                        last_ok = mid;
                        low = mid + 1;
                    }
                }

                int remain = req;
                if(last_ok >= 0)
                {
                    current_cost += temp[last_ok].first;
                    remain -= temp[last_ok].second;
                }

                if(remain > 0)
                {
                    last_ok++;

                    current_cost += remain * offer_list_for_cities[current_city][last_ok].first;
                }
            }

            cout<<current_cost<<" "<<ans_max_cost<<" "<<index<<endl;

            ans_max_cost = min(ans_max_cost, current_cost);
        }
    }

    cout << ans_max_day << " " << ans_max_cost << endl;

    return 0;
}
