CIRCLE getmec(vector<PT> &p) {
    int n = p.size();
    random_shuffle(p.begin(), p.end());
    CIRCLE c = {p[0], 0};
    for (int i = 1; i < n; i++) {
        if (judge(c.r, (c.o - p[i]).length()) == -1) {
            c = {p[i], 0};
            for (int j = 0; j < i; j++) {
                if (judge(c.r, (c.o - p[j]).length()) == -1) {
                    c = {(p[i] + p[j]) / 2, (p[i] - p[j]).length() / 2};
                    for (int k = 0; k < j; k++) {
                        if (judge(c.r, (c.o - p[k]).length()) == -1)
                            c = getcircle(p[i], p[j], p[k]);
                    }
                }
            }
        }
    }
    return c;
}