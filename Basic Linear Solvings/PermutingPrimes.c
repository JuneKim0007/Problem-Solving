
    #include <stdio.h>
    long divisors [60000]; 
    int static_idx =0;

    void permutation(int arr[], int n, int index, int currentProduct, int used, long result[]) 
    {
        if (index == n) {
            if (used) { 
                result[static_idx++] = currentProduct;
            }
            return;
        }
        permutation(arr, n, index + 1, currentProduct, used, result);
        permutation(arr, n, index + 1, currentProduct * arr[index], 1, result);
    }

    void permutation2(int arr[][60], int n) {
        int ans[15][60];

        int arr2[n];
        for (int i = 0; i<n; i++)
            arr2[i] = arr[i][1];

        permutation(arr2, n, 0, 1, 0, divisors);
        for (int i =0; i <n; i++)
        {
            int temp_idx = static_idx;
            for(int j =1; j <arr[i][0]-1; j++)
            {   
                int f = arr[i][1];
                for (int k = 0; k < temp_idx; k++)
                {
                    if (divisors[k] % f == 0)
                    {
                        divisors[static_idx++] = divisors[k]*arr[i][j];
                    }
                }
            }
        }

    }

    int main()
    {

        long n;
        scanf("%ld", &n);
        //any odd number is not perfect number as far as current mathematics knows.
        if (n % 2 !=0)
        {
            printf("NOT PERFECT\n");
            return 0;
        }

        const long const_n = n;
        int prime_divisor_list [15][60];
        int x = -1;
        int y = 1;
        for (int i =2; i<=n; i++)
        { 
            if(n%i == 0) 
            {
                x++;
                y=1;
            }
            for (int pow_i = i; n % i == 0; pow_i *= i) 
            {
                prime_divisor_list[x][y++] = pow_i;
                n /= i;
            }
            prime_divisor_list[x][0] = y;
        }
        permutation2(prime_divisor_list, x+1);

        long sum = 1-const_n;

        for (int i =static_idx; i>=0; i--)
        {
            sum+= divisors[i];
            if (sum > const_n){
                printf("NOT PERFECT\n");
                return 0;
            }
        }
        if(sum == const_n) printf("PERFECT\n");
        else printf("NOT PERFECT\n");
        return 0;
    }

