// 求子集和 或超集和 -> !(mask & (1 << i))
for(int i = 0; i<(1<<N); ++i)	F[i] = A[i]; //預處理 狀態權重

for(int i = 0;i < N; ++i)
for (int mask = (1<<N)-1; mask >= 0 ; mask--)
	if (mask & (1 << i))
		F[mask] += F[mask ^ (1 << i)];