//nya's library of simplex
//A*X <= B
//minimize C*X

#define REP(i,n) for(int i = 0; i < (int)(n); i++) 
#define FOR(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i) 
#define ALLOF(c) ((c).begin()), ((c).end()) 

const double EPS = 1.0e-10; 
const double INF = numeric_limits<double>::infinity(); 
  
typedef vector<double> vector_t; 
typedef vector<vector_t> matrix_t; 
  
vector_t simplex(matrix_t A, vector_t b, vector_t c) { 
  
    const int n = c.size(), m = b.size(); 
  
    // modify b to non-negative 
    REP(i, m) if (b[i] < 0) { 
        REP(j, n) 
            A[i][j] *= -1; 
        b[i] *= -1; 
    } 
  
    // list of base/independent variable ids 
    vector<int> bx(m), nx(n); 
    REP(i, m) 
        bx[i] = n+i; 
    REP(i, n) 
        nx[i] = i; 
  
    // extend A, b 
    A.resize(m+2); 
    REP(i, m+2) 
        A[i].resize(n+m, 0); 
    REP(i, m) 
        A[i][n+i] = 1; 
    REP(i, m) REP(j, n) 
        A[m][j] += A[i][j]; 
    b.push_back(accumulate(ALLOF(b), (double)0.0)); 
    REP(j, n) 
        A[m+1][j] = -c[j]; 
    REP(i, m) 
        A[m+1][n+i] = -INF; 
    b.push_back(0); 
  
    // main optimization 
    REP(phase, 2) { 
  
        for(;;) { 
  
            // select an independent variable 
            int ni = -1; 
            REP(i, n) 
                if (A[m][nx[i]] > EPS && (ni < 0 || nx[i] < nx[ni])) 
                    ni = i; 
            if (ni < 0) 
                break; 
  
            int nv = nx[ni]; 
  
            // select a base variable 
            vector_t bound(m); 
            REP(i, m) 
                bound[i] = (A[i][nv] < EPS ? INF : b[i] / A[i][nv]); 
            if (!(*min_element(ALLOF(bound)) < INF)) 
                return vector_t(); // -infinity 
  
            int bi = 0; 
            REP(i, m) 
                if (bound[i] < bound[bi]-EPS || (bound[i] < bound[bi]+EPS && bx[i] < bx[bi])) 
                    bi = i; 
  
            // pivot 
            double pd = A[bi][nv]; 
            REP(j, n+m) 
                A[bi][j] /= pd; 
            b[bi] /= pd; 
  
            REP(i, m+2) if (i != bi) { 
                double pn = A[i][nv]; 
                REP(j, n+m) 
                    A[i][j] -= A[bi][j] * pn; 
                b[i] -= b[bi] * pn; 
            } 
  
            swap(nx[ni], bx[bi]); 
        } 
  
        if (phase == 0 && abs(b[m]) > EPS) 
            return vector_t(); // no solution 
  
        A[m].swap(A[m+1]); 
        swap(b[m], b[m+1]); 
    } 
  
    vector_t x(n+m, 0); 
    REP(i, m) 
        x[bx[i]] = b[i]; 
    x.resize(n); 
  
    return x; 
}