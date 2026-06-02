#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 10
#define MAX1 100
#define EPS 1e-3
#define MAX_LOOP 1000

void nhapMaTranGauss(float a[MAX1][MAX1], int n) {
    printf("Nhap ma tran mo rong gom %d dong va %d cot:\n", n, n + 1);

    for (int i = 0; i < n; i++) {
        printf("Nhap dong %d:\n", i + 1);
        for (int j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }
}

void xuatMaTranGauss(float a[MAX1][MAX1], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%10.3f ", a[i][j]);
        }
        printf("\n");
    }
}

void doiDong(float a[MAX1][MAX1], int n, int dong1, int dong2) {
    for (int j = 0; j <= n; j++) {
        float temp = a[dong1][j];
        a[dong1][j] = a[dong2][j];
        a[dong2][j] = temp;
    }
}

int gauss(float a[MAX1][MAX1], float x[MAX1], int n) {
    for (int i = 0; i < n - 1; i++) {

        if (fabs(a[i][i]) < EPS) {
            int dongCanDoi = -1;

            for (int k = i + 1; k < n; k++) {
                if (fabs(a[k][i]) > EPS) {
                    dongCanDoi = k;
                    break;
                }
            }

            if (dongCanDoi == -1) {
                printf("He khong co nghiem duy nhat hoac khong xu ly duoc.\n");
                return 0;
            }

            doiDong(a, n, i, dongCanDoi);
        }

        for (int j = i + 1; j < n; j++) {
            float m = -a[j][i] / a[i][i];

            for (int k = i; k <= n; k++) {
                a[j][k] = a[j][k] + m * a[i][k];
            }
        }
    }

    if (fabs(a[n - 1][n - 1]) < EPS) {
        printf("He khong co nghiem duy nhat.\n");
        return 0;
    }

    for (int i = n - 1; i >= 0; i--) {
        float s = 0;

        for (int j = i + 1; j < n; j++) {
            s += a[i][j] * x[j];
        }

        x[i] = (a[i][n] - s) / a[i][i];
    }

    return 1;
}

void nhapNghiemBanDau(float x[MAX], int n) {
    printf("Nhap xap xi nghiem ban dau:\n");

    for (int i = 0; i < n; i++) {
        printf("x%d = ", i + 1);
        scanf("%f", &x[i]);
    }
}

int kiemTraCheoKhac0(float a[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        if (fabs(a[i][i]) < 1e-9) {
            return 0;
        }
    }
    return 1;
}

int gaussSiedel(float a[MAX][MAX], float x[MAX], int n) {
    int lap;
    int dem = 0;

    if (!kiemTraCheoKhac0(a, n)) {
        printf("Khong the lap vi co phan tu cheo chinh bang 0.\n");
        printf("Can doi dong de a[i][i] khac 0.\n");
        return 0;
    }

    do {
        lap = 0;
        dem++;

        printf("\nLan lap %d:\n", dem);

        for (int i = 0; i < n; i++) {
            float old = x[i];
            float s = 0;

            for (int j = 0; j < n; j++) {
                if (j != i) {
                    s += a[i][j] * x[j];
                }
            }

            x[i] = (a[i][n] - s) / a[i][i];

            if (fabs(x[i] - old) >= EPS) {
                lap = 1;
            }

            printf("x%d = %.6f  ", i + 1, x[i]);
        }

        printf("\n");

        if (dem >= MAX_LOOP) {
            printf("Qua so lan lap toi da. He co the khong hoi tu.\n");
            return 0;
        }

    } while (lap);

    printf("\nNghiem gan dung sau %d lan lap:\n", dem);
    for (int i = 0; i < n; i++) {
        printf("x%d = %.6f\n", i + 1, x[i]);
    }

    return 1;
}

void nhapMaTranBangFile(double A[][MAX + 1], int *n) {
    char tenFile[100];
    printf("Nhap ten file: ");
    scanf("%s", tenFile);
    FILE *f = fopen(tenFile, "r");
    if (f == NULL) {
        printf("Khong mo duoc file!\n");
        return;
    }
    fscanf(f, "%d", n);
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j <= *n; j++) {
            fscanf(f, "%lf", &A[i][j]);
        }
    }
    fclose(f);
}

void giamDu(double A[][MAX + 1], int n) {
    double x[MAX] = {0};
    double r[MAX];
    int k;
    double max, d;

    for (int i = 0; i < n; i++) {
        double pivot = A[i][i];
        if (pivot == 0) {
            printf("Duong cheo bang 0!\n");
            return;
        }
        for (int j = 0; j <= n; j++) {
            if (j != i) {
                A[i][j] /= pivot;
            }
        }
        A[i][i] = 1;
    }

    for (int i = 0; i < n; i++) {
        r[i] = A[i][n];
        for (int j = 0; j < n; j++) {
            r[i] -= A[i][j] * x[j];
        }
    }

    printf("\nBang lap:\n");
    for (int i = 0; i < n; i++) {
        printf("   x%-3d |", i + 1);
    }
    for (int i = 0; i < n; i++) {
        if ( i == n - 1) 
            printf("   R%-3d ", i + 1);
        else 
            printf("   R%-3d |", i + 1);
    }
    printf("\n-----------------------------------------------------\n");

    while(1) {
        max = fabs(r[0]);
        k = 0;
        for (int i = 1; i < n; i++) {
            if (fabs(r[i]) > max) {
                max = fabs(r[i]);
                k = i;
            }
        }
        for (int i = 0; i < n; i++) {
            printf(" %-7.3lf|", x[i]);
        }
        for (int i = 0; i < n; i++) {
            if (i == n - 1)
                printf(" %-7.3lf", r[i]);
            else
                printf(" %-7.3lf|", r[i]);
        }
        printf("\n");
        if (max < EPS) 
            break;
        x[k] += r[k];
        d = r[k];
        for (int i = 0; i < n; i++) {
            r[i] -= A[i][k] * d;
        }
    }
    printf("\nNghiem cua he:\n");
    for (int i = 0; i < n; i++) {
        printf("   x%d = %.3lf\n", i + 1, x[i]);
    }
}

void run1() {
    double A[MAX][MAX + 1];
    int n;

    nhapMaTranBangFile(A, &n);
    giamDu(A, n);
}

void nhapMaTranTriRiengOnly(double A[][MAX], int *n) {
    char tenFile[100];
    printf("Nhap ten file: ");
    scanf("%s", tenFile);
    FILE *f = fopen(tenFile, "r");
    if (f == NULL) {
        printf("Khong mo duoc file!\n");
        return;
    }
    fscanf(f, "%d", n);
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            fscanf(f, "%lf", &A[i][j]);
        }
    }
    fclose(f);
}

void nhanMaTranTriRiengOnly(double A[][MAX], double B[][MAX], double C[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void xuatMaTranTriRiengOnly(double A[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%10.3lf ", A[i][j]);
        }
        printf("\n");
    }
}

void giaiBac2TriRiengOnly(double a, double b, double c, double r[]) {
    double delta = b*b - 4*a*c;
    if(delta > 0) {
        r[0] = (-b + sqrt(delta)) / (2*a);
        r[1] = (-b - sqrt(delta)) / (2*a);
    }
    else if(delta == 0) {
        r[0] = -b / (2*a);
        r[1] = r[0];
    }
    else {
        printf("Phuong trinh vo nghiem!\n");
    }
}

void giaiBac3TriRiengOnly(double a, double b, double c, double d, double r[]) {
    int dem = 0;
    for(int i = -100; i <= 100; i++) {
        double fx = a*i*i*i + b*i*i + c*i + d; 
        if(fabs(fx) < 1e-6) {
            r[dem++] = i;
        }
    }
    if(dem == 0) {
        printf("Khong tim duoc nghiem!\n");
    }
}

void danhilepskiTriRiengOnly(double A[][MAX], int n) {
    double M[MAX][MAX];
    double M1[MAX][MAX];
    double B[MAX][MAX];
    for (int k = n - 2; k >= 0; k--) {
        if (A[k + 1][k] == 0) {
            printf("Pivot = 0, khong the tiep tuc!\n");
            return;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != k) {
                    if (i == j) { 
                        M[i][j] = 1;
                        M1[i][j] = 1;
                    } else {
                        M[i][j] = 0;
                        M1[i][j] = 0;
                    }
                } else {
                    M1[i][j] = A[k + 1][j];
                    if (j == k) {
                        M[i][j] = 1.0 / A[k + 1][k];
                    } else {
                        M[i][j] = -A[k + 1][j] / A[k + 1][k];
                    }
                }
            }
        }
        nhanMaTranTriRiengOnly(A, M, B, n);
        nhanMaTranTriRiengOnly(M1, B, A, n);
        printf("\nMa tran sau buoc k = %d:\n", n - k - 1);
        xuatMaTranTriRiengOnly(A, n);
    }
}

void timNghiemTriRiengOnly(double A[][MAX], int n) {
    double r[10];
    danhilepskiTriRiengOnly(A, n);
    printf("\nMa tran Frobenius:\n");
    xuatMaTranTriRiengOnly(A, n);
    printf("\nPhuong trinh dac trung:\n");
    printf("     r^%d", n);
    for (int j = 0; j < n; j++) {
        if (A[0][j] >= 0) 
            printf(" - %.3lf", A[0][j]);
        else 
            printf(" + %.3lf", -A[0][j]);
        if (j != n - 1) {
            int mu = n - j - 1;
            if (mu == 1)
                printf("r");
            else 
                printf("r^%d", mu);
        }
    }
    printf(" = 0\n");
    if (n == 2) {
        double a = 1, b = -A[0][0], c = -A[0][1];
        giaiBac2TriRiengOnly(a, b, c, r);
        printf("\nGia tri rieng: ");
        for(int i = 0; i < 2; i++) {
            printf("\n     r%d = %.3lf", i + 1, r[i]);
        } 
    }
    if (n == 3){
        double a = 1, b = -A[0][0], c = -A[0][1], d = -A[0][2];
        giaiBac3TriRiengOnly(a, b, c, d, r);
        printf("\nGia tri rieng: ");
        for(int i = 0; i < 3; i++) {
            printf("\n     r%d = %.3lf", i + 1, r[i]);
        }
    }
    printf("\n");
}

void run2() {
    int n;
    double A[MAX][MAX];
    nhapMaTranTriRiengOnly(A, &n);
    printf("\nMa tran ban dau:\n");
    xuatMaTranTriRiengOnly(A, n);
    timNghiemTriRiengOnly(A, n);
}

void nhapMaTran(double A[][MAX], int *n) {
    char tenFile[100];
    printf("Nhap ten file: ");
    scanf("%s", tenFile);
    FILE *f = fopen(tenFile, "r");
    if (f == NULL) {
        printf("Khong mo duoc file!\n");
        return;
    }
    fscanf(f, "%d", n);
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            fscanf(f, "%lf", &A[i][j]);
        }
    }
    fclose(f);
}

void nhanMaTran(double A[][MAX], double B[][MAX], double C[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void xuatMaTran(double A[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%10.3lf ", A[i][j]);
        }
        printf("\n");
    }
}

void taoDonVi(double A[][MAX], int n) {
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                A[i][j] = 1;
            else
                A[i][j] = 0;
        }
    }
}

void giaiBac2(double a, double b, double c, double r[]) {
    double delta = b*b - 4*a*c;
    if(delta > 0) {
        r[0] = (-b + sqrt(delta)) / (2*a);
        r[1] = (-b - sqrt(delta)) / (2*a);
    }
    else if(delta == 0) {
        r[0] = -b / (2*a);
        r[1] = r[0];
    }
    else {
        printf("Phuong trinh vo nghiem!\n");
    }
}

void giaiBac3(double a, double b, double c, double d, double r[]) {
    int dem = 0;
    for(int i = -100; i <= 100; i++) {
        double fx = a*i*i*i + b*i*i + c*i + d; 
        if(fabs(fx) < 1e-6) {
            r[dem++] = i;
        }
    }
    if(dem == 0) {
        printf("Khong tim duoc nghiem!\n");
    }
}

void danhilepski(double A[][MAX], double C[][MAX], int n) {
    double M[MAX][MAX];
    double M1[MAX][MAX];
    double B[MAX][MAX];
    taoDonVi(C, n);
    for (int k = n - 2; k >= 0; k--) {
        if (A[k + 1][k] == 0) {
            printf("Pivot = 0, khong the tiep tuc!\n");
            return;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != k) {
                    if (i == j) { 
                        M[i][j] = 1;
                        M1[i][j] = 1;
                    } else {
                        M[i][j] = 0;
                        M1[i][j] = 0;
                    }
                } else {
                    M1[i][j] = A[k + 1][j];
                    if (j == k) {
                        M[i][j] = 1.0 / A[k + 1][k];
                    } else {
                        M[i][j] = -A[k + 1][j] / A[k + 1][k];
                    }
                }
            }
        }
        nhanMaTran(A, M, B, n);
        nhanMaTran(M1, B, A, n);
        nhanMaTran(C, M, B, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                C[i][j] = B[i][j];
            }
        }
        printf("\nMa tran C sau buoc k = %d:\n", n - k - 1);
        xuatMaTran(C, n);
    }
}

void timVectoRieng(double C[][MAX], double r, int n, int k) {
    double x[MAX], y[MAX];
    for (int i = 0; i < n; i++) {
        y[i] = pow(r, n - i - 1);
    }
    for (int i = 0; i < n; i++) {
        x[i] = 0;
        for (int j = 0; j < n; j++) {
            x[i] += C[i][j] * y[j];
        }
    }
    printf("\nVecto rieng ung voi r%d = %.3lf: \n", k, r);
    printf("     x%d = (", k);
    for (int i = 0; i < n; i++) {
        printf("%.3lf", x[i]);
        if (i != n - 1)
            printf(", ");
    }
    printf(")\n");
}

void timNghiem(double A[][MAX], double C[][MAX], int n) {
    double r[10];
    danhilepski(A, C, n);
    printf("\nMa tran Frobenius:\n");
    xuatMaTran(A, n);
    printf("\nPhuong trinh dac trung:\n");
    printf("     r^%d", n);
    for (int j = 0; j < n; j++) {
        if (A[0][j] >= 0) 
            printf(" - %.3lf", A[0][j]);
        else 
            printf(" + %.3lf", -A[0][j]);
        if (j != n - 1) {
            int mu = n - j - 1;
            if (mu == 1)
                printf("r");
            else 
                printf("r^%d", mu);
        }
    }
    printf(" = 0\n");
    if (n == 2) {
        double a = 1, b = -A[0][0], c = -A[0][1];
        giaiBac2(a, b, c, r);
        printf("\nGia tri rieng: ");
        for(int i = 0; i < 2; i++) {
            printf("\n     r%d = %.3lf", i + 1, r[i]);
        } 
        printf("\n");
        for (int i = 0; i < 2; i++) {
            timVectoRieng(C, r[i], n, i + 1);
        }
    }
    if (n == 3){
        double a = 1, b = -A[0][0], c = -A[0][1], d = -A[0][2];
        giaiBac3(a, b, c, d, r);
        printf("\nGia tri rieng: ");
        for(int i = 0; i < 3; i++) {
            printf("\n     r%d = %.3lf", i + 1, r[i]);
        }
        printf("\n");
        for (int i = 0; i < 3; i++) {
            timVectoRieng(C, r[i], n, i + 1);
        }
    }
}

void run3() {
    int n;
    double A[MAX][MAX], C[MAX][MAX];
    nhapMaTran(A, &n);
    printf("\nMa tran ban dau:\n");
    xuatMaTran(A, n);
    timNghiem(A, C, n);
}

void nhap(double x[], double y[], int n){
	printf("x: ");
	for(int i = 0; i < n; i++){
	    scanf("%lf", &x[i]);
	}
	printf("y: ");
	for(int i = 0; i < n; i++){
	    scanf("%lf", &y[i]);
	}
}

void docFile(double x[], double y[], int *n, double *c){
    char tenFile[100];
    printf("Nhap ten file: ");
    scanf("%s", tenFile);
    FILE *f = fopen(tenFile, "r");
    if(f == NULL){
        printf("Khong mo duoc file!\n");
        return;
    }
    fscanf(f, "%d", n);
    fscanf(f, "%lf", c);
    for(int i = 0; i < *n; i++){
        fscanf(f, "%lf", &x[i]);
    }
    for(int i = 0; i < *n; i++){
        fscanf(f, "%lf", &y[i]);
    }
    fclose(f);
    printf("Doc file thanh cong!\n");
}

void bangAyken(double x[], int n, double c){
    printf("\nBang noi suy Ayken:\n\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                printf("%10.2lf", c - x[i]);
            }
            else{
                printf("%10.2lf", x[i] - x[j]);
            }
        }
        double d = c - x[i];
        for(int j = 0; j < n; j++){
            if(i != j)
                d *= (x[i] - x[j]);
        }
        printf(" | %10.2lf", d);
        printf("\n");
    }
    printf("\n\n");
}

void ayken(double x[], double y[], int n, double c){
	double w = 1, s = 0;
	for(int i = 0; i < n; i++){
		w = w * (c - x[i]);
		double d = c - x[i];
		for(int j = 0; j < n; j++){
			if(j != i) d = d * (x[i] - x[j]);
		}
		s = s + y[i] / d;
	}
	double kq = w * s;
	printf("W(%.2lf) = %.2lf", c, w);
	printf("\n");
	printf("f(%.2lf) = %.2lf", c, kq);
}

void bangSaiPhan(double a[][100], double x[], double y[], int n){
	for(int i = 0; i < n; i++){
		a[i][0] = y[i];
	}
	for(int j = 1; j < n; j++){
        for(int i = j; i < n; i++){ 
            a[i][j] = a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    printf("------------------------------------------------------------\n");

    printf("%-8s%-10s%-10s%-10s%-10s%-10s\n",
           "xi", "f(xi)", "d1f", "d2f", "d3f", "d4f");
    printf("------------------------------------------------------------\n");
    for(int i = 0; i < n; i++){
    	printf("%-8.0lf", x[i]);
    	printf("%-10.2lf", a[i][0]);
    	for(int j = 1; j < n; j++){
    		if(i >= j)
    			printf("%-10.2lf", a[i][j]);
    		else
    			printf("%-10s", "");
		}
		printf("\n");
	}
    printf("------------------------------------------------------------\n");
}

double fTichPhan(double x) {
    return 1.0 / (1 + x * x);
}

// ================== 1. CONG THUC HINH THANG ==================

void nhapHinhThang(long long *a, long long *b, long long *n) {
    printf("Nhap lan luot a, b, n: ");
    scanf("%lld %lld %lld", a, b, n);
}

void thucHienHinhThang(long long a, long long b, long long n, double (*f)(double)) {
    if (n == 0) {
        printf("n phai khac 0");
        return;
    }

    int i;
    double h = 1.0 * (b - a) / n;
    double J = (f(a) + f(b)) / 2;

    for (i = 1; i < n; i++) {
        J += f(a + i * h);
    }

    J = J * h;
    printf("Xuat ket qua: %.4lf", J);
}

void tichPhanHinhThang() {
    long long a, b, n;

    nhapHinhThang(&a, &b, &n);
    thucHienHinhThang(a, b, n, fTichPhan);
}


// ================== 2. CONG THUC PARABOL ==================

void nhapParabol(long long *a, long long *b, long long *n) {
    printf("Nhap lan luot a, b, n: ");
    scanf("%lld %lld %lld", a, b, n);
}

void thucHienParabol(long long a, long long b, long long n, double (*f)(double)) {
    if (n == 0) {
        printf("n phai khac 0");
        return;
    }

    int i;
    double h = (b - a) / (2.0 * n);
    double J = f(a) + f(b);

    for (i = 1; i < 2 * n; i++) {
        if (i % 2)
            J += 4 * f(a + i * h);
        else
            J += 2 * f(a + i * h);
    }

    J = h * J / 3.0;
    printf("Xuat ket qua: %.4lf", J);
}

void tichPhanParabol() {
    long long a, b, n;

    nhapParabol(&a, &b, &n);
    thucHienParabol(a, b, n, fTichPhan);
}


// ================== 3. CONG THUC NEWTON - COTET ==================

void nhapNewtonCotet(double *a, double *b, int *n) {
    printf("Nhap a, b, n: ");
    scanf("%lf %lf %d", a, b, n);
}

double LNewtonCotet(int n, int i, double t) {
    double s = 1.0;
    int j;

    for (j = 0; j <= n; j++) {
        if (j != i) {
            s *= (t - 1.0 * j / n) / (1.0 * i / n - 1.0 * j / n);
        }
    }

    return s;
}

double PNewtonCotet(int n, int i) {
    int k;
    int m = 1000;
    double h = 1.0 / m;
    double tong = 0;
    double t;

    for (k = 0; k <= m; k++) {
        t = k * h;

        if (k == 0 || k == m)
            tong += LNewtonCotet(n, i, t);
        else
            tong += 2 * LNewtonCotet(n, i, t);
    }

    return h * tong / 2.0;
}

void thucHienNewtonCotet(double a, double b, int n, double (*f)(double)) {
    int i;
    double h = (b - a) / n;
    double J = 0;
    double x;

    for (i = 0; i <= n; i++) {
        x = a + i * h;
        J += f(x) * PNewtonCotet(n, i);
    }

    J = (b - a) * J;
    printf("Ket qua = %.4lf", J);
}

void tichPhanNewtonCotet() {
    double a, b;
    int n;

    nhapNewtonCotet(&a, &b, &n);
    thucHienNewtonCotet(a, b, n, fTichPhan);
}


//MENU
void menuGiaiHeTuyenTinh() {
    int chon;
    int n;

    do {
        printf("\n========== GIAI HE DAI SO TUYEN TINH ==========\n");
        printf("1. Giai bang phuong phap Gauss\n");
        printf("2. Giai bang phuong phap Gauss Siedel\n");
        printf("3. Giai bang phuong phap giam du\n");
        printf("0. Quay lai menu chinh\n");
        printf("Nhap lua chon: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1: {
                float a[MAX1][MAX1], x[MAX1];

                printf("\n--- GIAI HE BANG PHUONG PHAP GAUSS ---\n");
                printf("Nhap so an n = ");
                scanf("%d", &n);

                nhapMaTranGauss(a, n);

                printf("\nMa tran ban dau:\n");
                xuatMaTranGauss(a, n);

                if (gauss(a, x, n)) {
                    printf("\nMa tran sau khi khu Gauss:\n");
                    xuatMaTranGauss(a, n);

                    printf("\nNghiem cua he:\n");
                    for (int i = 0; i < n; i++) {
                        printf("x%d = %.6f\n", i + 1, x[i]);
                    }
                }

                break;
            }

            case 2: {
                float a[MAX][MAX], x[MAX];

                printf("\n--- GIAI HE BANG PHUONG PHAP GAUSS SIEDEL ---\n");
                printf("Nhap so an n = ");
                scanf("%d", &n);

                printf("Nhap ma tran mo rong gom %d dong va %d cot:\n", n, n + 1);
                for (int i = 0; i < n; i++) {
                    printf("Nhap dong %d: ", i + 1);
                    for (int j = 0; j <= n; j++) {
                        scanf("%f", &a[i][j]);
                    }
                }

                nhapNghiemBanDau(x, n);

                gaussSiedel(a, x, n);

                break;
            }

            case 3: {
                double A[MAX][MAX + 1];

                printf("\n--- GIAI HE BANG PHUONG PHAP GIAM DU ---\n");
                printf("Nhap so an n = ");
                scanf("%d", &n);

                printf("Nhap ma tran mo rong gom %d dong va %d cot:\n", n, n + 1);
                for (int i = 0; i < n; i++) {
                    printf("Nhap dong %d: ", i + 1);
                    for (int j = 0; j <= n; j++) {
                        scanf("%lf", &A[i][j]);
                    }
                }

                giamDu(A, n);

                break;
            }

            case 0:
                printf("\nQuay lai menu chinh...\n");
                break;

            default:
                printf("\nLua chon khong hop le!\n");
        }

    } while (chon != 0);
}

void menuTriRiengVectoRieng() {
    int chon;

    do {
        printf("\n========== TIM GIA TRI RIENG VA VECTO RIENG ==========\n");
        printf("1. Tim gia tri rieng va vecto rieng bang phuong phap Danhilepski\n");
        printf("0. Quay lai menu chinh\n");
        printf("Nhap lua chon: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
                run3();
                break;

            case 0:
                printf("\nQuay lai menu chinh...\n");
                break;

            default:
                printf("\nLua chon khong hop le!\n");
        }

    } while (chon != 0);
}

void menuNoiSuy() {
    int chon;
    int n;
    double c;
    double x[100], y[100];
    double a[100][100];

    do {
        printf("\n========== NOI SUY ==========\n");
        printf("1. Noi suy Ayken\n");
        printf("2. In bang sai phan\n");
        printf("0. Quay lai menu chinh\n");
        printf("Nhap lua chon: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1: {
                printf("\n--- NOI SUY AYKEN ---\n");
                docFile(x, y, &n, &c);

                printf("\nBang Ayken:\n");
                bangAyken(x, n, c);

                printf("\nKet qua noi suy:\n");
                ayken(x, y, n, c);

                printf("\n");

                break;
            }

            case 2: {
                printf("\n--- IN BANG SAI PHAN ---\n");
                docFile(x, y, &n, &c);

                printf("\nBang sai phan:\n");
                bangSaiPhan(a, x, y, n);

                break;
            }

            case 0:
                printf("\nQuay lai menu chinh...\n");
                break;

            default:
                printf("\nLua chon khong hop le!\n");
        }

    } while (chon != 0);
}

void menuTichPhan() {
    int chon;

    do {
        printf("\n========== TICH PHAN ==========\n");
        printf("1. Cong thuc hinh thang\n");
        printf("2. Cong thuc Parabol\n");
        printf("3. Cong thuc Newton-Cotet\n");
        printf("0. Quay lai menu chinh\n");
        printf("Nhap lua chon: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
                printf("\n--- CONG THUC HINH THANG ---\n");
                tichPhanHinhThang();
                break;

            case 2:
                printf("\n--- CONG THUC PARABOL ---\n");
                tichPhanParabol();
                break;

            case 3:
                printf("\n--- CONG THUC NEWTON-COTET ---\n");
                tichPhanNewtonCotet();
                break;

            case 0:
                printf("\nQuay lai menu chinh...\n");
                break;

            default:
                printf("\nLua chon khong hop le!\n");
        }

    } while (chon != 0);
}

int main() {
    int chon;

    do {
        printf("\n================ MENU CHINH ================\n");
        printf("1. Giai he dai so tuyen tinh\n");
        printf("2. Tim gia tri rieng va vecto rieng\n");
        printf("3. Noi suy\n");
        printf("4. Tich phan\n");
        printf("0. Thoat chuong trinh\n");
        printf("Nhap lua chon: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
                menuGiaiHeTuyenTinh();
                break;

            case 2:
                menuTriRiengVectoRieng();
                break;

            case 3:
                menuNoiSuy();
                break;

            case 4:
                menuTichPhan();
                break;

            case 0:
                printf("\nThoat chuong trinh.\n");
                break;

            default:
                printf("\nLua chon khong hop le! Vui long chon lai.\n");
        }

    } while (chon != 0);

    return 0;
}
