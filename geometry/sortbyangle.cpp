bool cmp(const Pt& lhs, const Pt rhs){
    return atan2(lhs.y, lhs.x) < atan2(rhs.y, rhs.x);
}
sort(P.begin(), P.end(), cmp);

bool cmp(const Pt& lhs, const Pt rhs){
    if((lhs < Pt(0, 0)) ^ (rhs < Pt(0, 0)))
        return (lhs < Pt(0, 0)) < (rhs < Pt(0, 0));
    return (lhs ^ rhs) > 0;
} // 從 270 度開始逆時針排序
 
sort(P.begin(), P.end(), cmp);