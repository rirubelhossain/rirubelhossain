private int[] fastmul(int[] a, int[] b) 
{ 
    if (allZero(a) || allZero(b)) 
    { 
        return new int[a.Length + b.Length]; 
    } 
    if (a.Length < 103) 
    { 
        return slowmul(a, b); 
    } 
    else 
    { 
        int k = a.Length / 2; 
        int[] p = new int[k]; 
        int[] q = new int[k]; 
        int[] r = new int[k]; 
        int[] s = new int[k]; 
        Array.Copy(a, 0, p, 0, k); 
        Array.Copy(a, k, q, 0, k); 
        Array.Copy(b, 0, r, 0, k); 
        Array.Copy(b, k, s, 0, k); 
        int[] pr = fastmul(p, r); 
        int[] qs = fastmul(q, s); 
        int[] pplusq = new int[k]; 
        for (int i = 0; i < k; ++i) 
            pplusq[i] = p[i] + q[i]; 
        int[] rpluss = new int[k]; 
        for (int i = 0; i < k; ++i) 
            rpluss[i] = r[i] + s[i]; 
        int[] tmp = fastmul(pplusq, rpluss); 
        for (int i = 0; i < 2 * k; ++i) 
            tmp[i] -= pr[i] + qs[i]; 
        int[] res = new int[4 * k]; 
        for (int i = 0; i < 2 * k; ++i) 
            res[i] += pr[i]; 
        for (int i = 0; i < 2 * k; ++i) 
            res[i + k] += tmp[i]; 
        for (int i = 0; i < 2 * k; ++i) 
            res[i + 2 * k] += qs[i]; 
        return res; 
    } 
} 

private bool allZero(int[] a) 
{ 
    for (int i = 0; i < a.Length; ++i) 
        if (a[i] != 0) 
            return false; 
    return true; 
} 

private int[] slowmul(int[] a, int[] b) 
{ 
    int[] c = new int[a.Length + b.Length]; 
    for (int i = 0; i < a.Length; ++i) 
        if (a[i] != 0) 
            for (int j = 0; j < b.Length; j += 1) 
            { 
                if (b[j] != 0) 
                    c[i + j] += a[i] * b[j]; 
            } 
    return c; 
} 