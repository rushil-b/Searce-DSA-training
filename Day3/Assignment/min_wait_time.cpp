//A program to calculate minimum average waiting time

//Name - Rushil Bangia

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int, int> pii;

int main() { //main function
    std::cout << "Enter number of customers" << '\n';
    int n;
    cin >> n;
    vector<pair<long long, long long>> v(n); //input vector declared

    std::cout << "Enter 'time of ordering' and 'time duration of cooking' for each of the " <<n<<" customers-"<< '\n';

    for (int i = 0; i < n; i++) {
        std::cin >> v[i].first>>v[i].second;
    }

    sort(v.begin(), v.end()); //sorting the vector in terms of the first element of the pair,i.e., time of ordering

    long long sum = 0; //declared the total waiting time variable
    set<pair<int, int>> q; //declared the set 'q' which will store the non duplicated elements in sorted order on the basis of first element of thr pair.
    long long t = v[0].first;
    int it = 0;

    while (it < n || q.size()) { //loop will stop when both it is >= n and set 'q' is empty.
        while (it < n && v[it].first <= t) {
            q.insert(pii(v[it].second, it)); //inserting a pair in set
            ++it;
        }
        if (q.empty()) { //empty condition of set
            t = v[it].first;
        } else {
            int i = q.begin()->second;
            q.erase(q.begin()); //deleting first element of set
            t += v[i].second;
            sum += t-v[i].first;
        }
    }

    cout << '\n'<<"Minimum average waiting time- "<< sum / n << endl;

    return 0;
}
