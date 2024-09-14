int Euler(int n){
	int now = n;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0){
			now = now - now / i;
			while (n % i == 0) n = n / i;
        }
    if (n > 1) now = now - now / n;
    return now;
}