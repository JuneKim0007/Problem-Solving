#include <stdio.h>
#include <math.h>

int findMonth(int low, int high, double car_value, double loan, double dep_rate, double payment) {
    // Base case
    if (low + 1 == high) {
        double valLow  = car_value * pow(1 - dep_rate, low);
        double valHigh = car_value * pow(1 - dep_rate, high);
        double loanLow  = loan - payment * low;
        double loanHigh = loan - payment * high;

        if (loanLow < valLow) return low;   // already good at low
        if (loanHigh < valHigh) return high; // good at high
        return high; // fallback
    }

    int mid = (low + high) / 2;

    double valMid  = car_value * pow(1 - dep_rate, mid);
    double loanMid = loan - payment * mid;

    if (loanMid <= valMid) {
        // condition satisfied earlier
        return findMonth(low, mid, car_value, loan, dep_rate, payment);
    } else {
        // still owing more, go later
        return findMonth(mid, high, car_value, loan, dep_rate, payment);
    }
}

int main() {
    int duration, nRecords;
    double down, loan;

    scanf("%d %lf %lf %d", &duration, &down, &loan, &nRecords);

    int monthRec[110];
    double rateRec[110];
    for (int i = 0; i < nRecords; i++) {
        scanf("%d %lf", &monthRec[i], &rateRec[i]);
    }

    double payment = loan / duration;
    double car_value = loan + down;
    double owed = loan;

    // apply month 0 depreciation
    double dep = rateRec[0];
    car_value *= (1 - dep);

    if (owed < car_value) {
        printf("0 months\n");
        return 0;
    }

    int nextRec = 1, answer = -1;
    for (int i = 0; i < nRecords; i++) {
        int start = monthRec[i];
        int end = (i + 1 < nRecords) ? monthRec[i + 1] : duration;

        int found = findMonth(start, end, car_value, owed, rateRec[i], payment);
        if (found < end) {
            answer = found;
            break;
        }

        // update state to the end of this interval
        owed -= (end - start) * payment;
        car_value *= pow(1 - rateRec[i], end - start);
    }

    if (answer == -1) answer = duration;

    printf("%d month%s\n", answer, answer == 1 ? "" : "s");
    return 0;
}
