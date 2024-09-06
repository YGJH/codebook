int randint(int l, int r){
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<> dis(l, r); return dis(mt);
}