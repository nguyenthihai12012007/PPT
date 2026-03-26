#include <stdio.h>
#include <math.h>
#include "menu.h"

#define eps 1e-6
#define MAX 100

int n;
double A[MAX];

void hoocner1() {
    int n,c;
    printf("Nhap gia tri bac va c: ");
    scanf("%d%d",&n,&c);

    int a[n+1];
    printf("Nhap cac he so: ");
    for (int i=0;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    int p=a[0];
    
    for(int i=1;i<=n;i++) {
        p=p*c+a[i];
    }
    printf("Ket qua : %d\n",p);
}

void hoocnertq() {
    int n,c;
    printf("Nhap gia tri bac va c: ");
    scanf("%d%d",&n,&c);
    
    int a[n+1];
    printf("Nhap cac he so: "); 
    for(int i=0;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    
    int b[n+1][n+1];
    
    for(int i=0;i<=n;i++) {
        b[0][i]=a[i];
    }
    
    for(int i=1;i<=n;i++) {
        for(int j=0;j<n;j++) {
            b[i][j]=b[i-1][j]*c+b[i-1][j+1];
        }
    }
    
    printf("Cac he so cua hoocner tong quat: ");
    for(int i=0;i<=n;i++) {
        printf("%d ",b[i][0]);
    }
    printf("\n");
}

void cosx() {
    double x;
    printf("Nhap gia tri x: ");
    scanf("%lld",&x);
    double sum=1;
    double term=1;
    int k=0;
    
    while(fabs(term)>eps) {
        k++;
        term=term*(-x*x)/((2*k)*(2*k-1));
        sum+=term;
    }
    
    printf("%lld",sum);
    printf("\n");
}

void sinx() {
    double x;
    printf("Nhap gia tri x: ");
    scanf("%lld",&x);
    double sum=x;
    double term=x;
    int k=0;
    while(fabs(term)>eps) {
        k++;
        term=term*(-x*x)/((2*k+1)*(2*k));
        sum+=term;
    }
    
    printf("%lld",sum);
    printf("\n");
}

void emux() {
    double x;
    printf("Nhap gia tri x: ");
    scanf("%lld",&x);
    double sum=1;
    double term=1;
    int k=0;
    while(fabs(term)>eps) {
        k++;
        term=term*x/k;
        sum+=term;
    }
    
    printf("%lld",sum);
    printf("\n");
}

void dinhly3(int n, int a[]) {
    double m1 = 0, m2 = 0;

    for(int i = 1; i <= n; i++) {
        if (fabs(a[i]) > m1) {
            m1 = fabs(a[i]);
        }
    }

    for(int i = 0; i < n; i++) {
        if (fabs(a[i]) > m2) {
            m2 = fabs(a[i]);
        }
    }

    double x1 = fabs(a[n]) / (m2 + fabs(a[n]));
    double x2 = 1 + m1 / fabs(a[0]);

    printf("%.5lf <= |x| <= %.5lf\n", x1, x2);
}

double dinhly4(int n, int a[]) {
    if (a[0] < 0) {
        for (int i = 0; i <= n; i++) {
            a[i] *= -1;
        }
    }

    int amax = 0;
    for (int i = 1; i <= n; i++) {
        if (abs(a[i]) > amax) {
            amax = abs(a[i]);
        }
    }

    int m = -1;
    for (int i = 1; i <= n; i++) {
        if (a[i] < 0) {
            m = n - i;
            break;
        }
    }

    if (m == -1) {
        return -1;
    }

    return 1.0 + pow((double)amax / a[0], 1.0 / m);
}

double f(double x) {
    double p = A[0];
    for (int i = 1; i <= n; i++) {
        p = p * x + A[i];
    }
    return p;
}

void chiadoi() {
    double c, a, b, EPS;
    double fa,fb,fc;
    
    printf("Nhap bac da thuc n = ");
    scanf("%d", &n);
    
    printf("Nhap cac he so cua da thuc: ");
    for (int i = 0; i <= n; i++) {
        scanf("%lf", &A[i]);
    }
    
    printf("\nNhap a = ");
    scanf("%lf", &a);
    printf("Nhap b = ");
    scanf("%lf", &b);
    printf("Nhap sai so eps = ");
    scanf("%lf", &EPS);
    
    fa=f(a);
    fb=f(b);
    
    if (fa * fb >= 0) {
        printf("Khoang [a,b] khong hop le!\n");
        return;
    }
    
    printf("\nBang lap:\n");
    printf("     a    |     b    |     c    |   f(c)\n");
    printf("  ----------------------------------------\n");
    
    do {
        c = (a + b) / 2.0;
        fc=f(c);
        printf("%8.3lf  |%8.3lf  |%8.3lf  |%8.3lf\n", a, b, c, fc);
        if (fa * fc < 0) {
            b = c;
            fb=fc;
        } else {
            a = c;
            fa=fc;
        }
    } while ((fabs(a-b) > eps) ); 
    
    printf("\nNghiem gan dung x = %.10lf\n", c);
}

int main() {
    int choice;

    do {
        menu();
        printf("\n");

        if (scanf("%d", &choice) != 1) {   
            printf("Loi: Vui long chi nhap chu so!\n");
            getchar();
            continue;
        }

        switch(choice) {
            case 1:
                xuLyMenuHoocner();
                break;
            case 2: 
                xulyMenuMaclaurin();
                break;
            case 3:
                xulyMenuTachNghiem();
                break;
            case 4:
                menu_timnghiem();
                printf("\n");
                break;
            case 0:
                printf("Da thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while(choice != 0);

    return 0;
}

