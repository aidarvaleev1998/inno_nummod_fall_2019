#include <stdio.h>
#include <math.h>
#include "blackbox.h"

int main() {
    int n;
    scanf("%d", &n);
    blackbox_init(n);
    
	const size_t num_steps = 19e3;
	const double h = 2.0 / num_steps;

    double sum = 0;
    double sum_even = 0;
    for (size_t i = 1; i < num_steps - 1; i += 2) {
        sum += blackbox(-1 + i * h);
        sum_even += blackbox(-1 + (i + 1) * h);
    }
    sum = 4 * (sum + blackbox(-1 + (num_steps - 1) * h))  + 2 * sum_even;
    sum += blackbox(-1) + blackbox(1);
    sum *= h / 3;

    printf("%.12lf", sum);

    return 0;
}