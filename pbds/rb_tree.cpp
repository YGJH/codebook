#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
template<typename T> using pbds_no_equal   = tree<T, null_type, less<T>, 	   rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using pbds_with_equal = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
pbds_no_equal<int> s;
// if not exist return false
template<typename T>
bool check_x_exist(T x){
    return (s.find(x) != s.end());
}
int main(){
    // Insert some entries into s.
    s.insert(12); s.insert(505);
    // The order of the keys should be: 12, 505.
    assert(*s.find_by_order(0) == 12);
    assert(*s.find_by_order(3) == 505);
    // The order of the keys should be: 12, 505.
    assert(s.order_of_key(12) == 0);
    assert(s.order_of_key(505) == 1);
    // Erase an entry.
    s.erase(12);
    // The order of the keys should be: 505.
    assert(*s.find_by_order(0) == 505);
    // The order of the keys should be: 505.
    assert(s.order_of_key(505) == 0);
    // 查詢名次 k 是那個人的成績
    int rank=s.size()-s.order_of_key(k);
    cout << s.size() << endl;
}