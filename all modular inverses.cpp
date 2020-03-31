	r[1] = 1;
	for (i = 2; i < MOD; ++i)
		r[i] = (MOD - (MOD/i) * r[MOD%i] % MOD) % MOD;
