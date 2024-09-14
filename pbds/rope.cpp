#include <iostream>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;

signed main() { // log n
    rope<int> a; 
    crope r = "Hello world"; // equal to rope<char> st
    crope orr = "I m charles";
    int pos = 1;
    char x = 'x';
    int i = 3;
    int len = 4;
    r.push_back(x);
    orr+=x; //在最後加上 x
    cerr << orr << endl;
    r.pop_back(); //去掉最後一個元素
    r.insert(pos, x); //在 pos 位置加入 x
    r.erase(pos, x); //從 pos 位置刪除 x 個元素
    r.copy(pos, len, "x"); //從 pos 開始的 len 個元素用 x 代替
    r.replace(pos, x); //從 pos 開始的元素全部換成 x
    r.substr(pos, x); //取得以 pos 開始的 x 個元素
    r.at(i);orr[i]; //詢問第 i 個元素
    return 0;
} 