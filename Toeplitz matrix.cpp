//All diagonals same. O(n^2)
double[] levinson(double[] A, double[] b) {
 int n = (A.length + 1) / 2, ZERO = n - 1;
 double[] x = new double[n], fs = new double[n], bs = new double[n];
 fs[0] = bs[0] = 1 / A[ZERO];
 x[0] = b[0] / A[ZERO];
 for (int i = 1; i < n; i++) {
 double ef = 0, eb = 0, ex = 0;
  for (int j = 0; j < i; j++) {
 ef += fs[j] * A[i - j + ZERO];
 eb += bs[j] * A[-1 - j + ZERO];
 ex += x[j] * A[i - j + ZERO];
 }
 if (abs(ef * eb - 1) < EPS) return null;
 for (int j = i; j >= 0; j--) {
 double af = (j < i ? fs[j] : 0), ab = (j != 0 ? bs[j - 1] : 0);
 fs[j] = af / (1 - ef * eb) - ef * ab / (1 - ef * eb);
 bs[j] = ab / (1 - ef * eb) - eb * af / (1 - ef * eb);
 }
 for (int j = 0; j <= i; j++) x[j] += (b[i] - ex) * bs[j];
 }
 return x;
 }