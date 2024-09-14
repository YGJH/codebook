int RoatingCalipers(vector<PT> &tubao) { // 最遠點對 回傳距離平方
    int nn = tubao.size();
    int ret = 0;
    if (tubao.size() <= 2) {
        return (tubao[0] - tubao[1]).length2();
    }
    for (int i = 0, j = 2; i < nn; i++) {
        PT a = tubao[i], b = tubao[(i + 1) % nn];
        while (((a - tubao[j]) ^ (b - tubao[j])) <
               ((a - tubao[(j + 1) % nn]) ^ (b - tubao[(j + 1) % nn])))
            j = (j + 1) % nn;
        ret = max(ret, (a - tubao[j]).length2());
        ret = max(ret, (b - tubao[j]).length2());
    }
    return ret;
}