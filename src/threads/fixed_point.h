#define INT_MAX ((1<<31)-1)
#define INT_MIN (-(1<<31))
#define F ((1<<14))

int int_to_fp(int n);
int fp_to_int_tozero(int x);
int fp_to_int_nearest(int x);
int fp_add_fp(int x, int y);
int fp_sub_fp(int x, int y);
int fp_add_int(int x, int n);
int fp_sub_int(int x, int n);
int fp_mul_fp(int x, int y);
int fp_mul_int(int x, int n);
int fp_div_fp(int x, int y);
int fp_div_int(int x, int n);

int int_to_fp(int n) { return n * F; }
int fp_to_int_tozero(int x) { return x / F; }
int fp_to_int_nearest(int x) { return x >= 0 ? (x + F / 2)/F : (x - F / 2)/F; }
int fp_add_fp(int x, int y) { return x + y; }
int fp_sub_fp(int x, int y) { return x - y; }
int fp_add_int(int x, int n) { return x + n * F; }
int fp_sub_int(int x, int n) { return x - n * F; }
int fp_mul_fp(int x, int y) { return ((int64_t)x) * y / F; }
int fp_mul_int(int x, int n) { return x * n; }
int fp_div_fp(int x, int y) { return ((int64_t)x) * F / y; }
int fp_div_int(int x, int n) { return x / n; }