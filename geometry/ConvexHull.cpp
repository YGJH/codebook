vector<Pt> Hull(vector<Pt> P){
	sort(all(P));
	P.erase(unique(all(P)),P.end());
	P.insert(P.end(),P.rbegin()+1,P.rend());
	vector<Pt> stk;
	for(auto p:P){
		auto it = stk.rbegin();
		while(stk.rend() - it >= 2 and \
		ori(*next(it),*it,p) <= 0L and \
		((*next(it) < *it) == (*it < p))) ++it;
		stk.resize(stk.rend() - it);
		stk.PB(p);
	}
	stk.pop_back();
	return stk;
}