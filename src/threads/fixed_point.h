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