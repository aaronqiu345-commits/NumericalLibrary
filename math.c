#include <stdio.h>
#include <math.h>
#include <unistd.h>
#define PI 3.1459265358979323846

int calcSine(void) {
    printf("x          Sin       Library   Difference \n");
    printf("-          ---       -------   ---------- \n");
    for (int i = -32; i < 32; i++) {
    double x = i*PI/16;
    double x2 = x*x;
    x = fmod(x, 2*PI);

    double sinNumer = x*(((-479249.0 * x2 + 52785432.0) * x2 - 1640635920.0) * x2 + 11511339840.0);
    double sinDenom = 7*(((2623.0 * x2 + 453960.0) * x2 + 39702960.0) * x2 + 1644477120.0);
    double sine = sinNumer / sinDenom;
    double sineLib = sin(x);
    double sineDiff = fabs(sine - sineLib);
    printf("%f %f %f %f \n", x, sine, sineLib, sineDiff);
    }
    return 0;
}

int calcCosine(void) {
    printf("x          Cos       Library   Difference \n");
    printf("-          ---       -------   ---------- \n");
    for (int i = -32; i < 32; i++) {
    double x = i*PI/16;
    double x2 = x*x;
    x = fmod(x, 2*PI);

    double cosNumer = (x2*(1075032 - 14615*x2) - 18471600)*x2 + 39251520;
    double cosDenom = ((127*x2 + 16632)*x2 + 1154160)*x2 + 39251520;
    double cosine = cosNumer / cosDenom;
    double cosineLib = cos(x);
    double cosineDiff = fabs(cosine - cosineLib);
    printf("%f %f %f %f \n", x, cosine, cosineLib, cosineDiff);
    }
    return 0;
}

int calcTangent(void) {
    printf("x          Tan       Library   Difference \n");
    printf("-          ---       -------   ---------- \n");
    for (double i = 0; i < 10 + 2/3; i++) {
        if (i == 11) {
            i = 10 + 2/3;
        }
    double x = i*PI/16;
    double x2 = x*x;
    x = fmod(x, PI);

    double tanNumer = x*((((x2 - 990.0) * x2 + 135135.0) * x2 - 4729725.0) * x2 + 34459425.0);
    double tanDenom = 45*((((x2 - 308.0) * x2 + 21021.0) * x2 - 360360.0) * x2 + 765765.0);
    double tangent = tanNumer / tanDenom;
    double tangentLib = tan(x);
    double tangentDiff = fabs(tangent - tangentLib);
    printf("%f %f %f %f \n", x, tangent, tangentLib, tangentDiff);
    }
    return 0;
}

int calcExponential(void) {
    printf("x          e         Library   Difference \n");
    printf("-          -         -------   ---------- \n");
    for (double i = 0; i < 9; i += 0.1) {
        const double epsil = 1e-9;
        double x = i;
        x = fmod(x, PI);
        double eLib = exp(x);
        double t = 1.0;
        double s = 1.0;

        for (int i = 1; fabs(t) > epsil; i++) {
            t = t * x / i;
            s += t;
        }
        double eDiff = fabs(s-eLib);
        printf("%f %f %f %f \n", x, s, eLib, eDiff);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int option;
    printf("%d \n", argc);
    if (argc == 1) {
            printf("To use this program, type ./math followed by any of the following: \n");
            printf("-s (sine), -c (cosine), -t (tangent), -e (exponential)\n");
            printf("i.e. ./math -s\n");
    }

    while ((option = getopt(argc, argv, "sctea")) != -1) {
        switch (option) {
            case 's':
                calcSine();
                break;
            case 'c':
                calcCosine();
                break;
            case 't':
                calcTangent();
                break;
            case 'e':
                calcExponential();
                break;
            case 'a':
                calcSine();
                calcCosine();
                calcTangent();
                calcExponential();
                break;
            default:
                printf("To use this program, type ./math followed by any of the following: \n");
                printf("-s (sine), -c (cosine), -t (tangent), -e (exponential), -a (all)\n");
                printf("i.e. ./math -s\n");
                break;
        }
    }
    return 0;
}