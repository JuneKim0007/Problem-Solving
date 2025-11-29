#include <stdio.h>

int main()
{
    int length; 
    scanf("%d", &length);
    char arr[3]; //to store the current direction of the Rod.
    
    char dir_p = 'x';
    char sec_p = 'x';
    
    int dir = 1;
    int curr_dir = 1;

    scanf("%2s", arr);
    length --;  
    if (arr[0] == '+'){
        curr_dir++;
        dir_p = arr[1];
    }
    else if (arr[0] == '-')
    {
        curr_dir += 3;
        dir_p = arr[1];
    }
    
    for (int i = 0; i < length - 1; i++) 
    {
        scanf("%2s", arr);
        if (arr[0] == 'N')
            continue;
        if (sec_p == '0')
        {
            sec_p = arr[1];
            if(arr[0] == '+')
                curr_dir++;
            else
                curr_dir += 3;
            continue;
        }
        if (dir_p == arr[1])
        {
            if(arr[0] == '+')
                curr_dir++;
            else
                curr_dir += 3;
        }

        else if (dir_p != arr[1] && sec_p == arr[1])
        {
            if (dir_p +arr[1] == 241)
                sec_p = 'z';
            else if (dir_p + arr[1] == 242)
                sec_p = 'y';
            else
                sec_p = 'x';
            if(arr[0] == '+')
                curr_dir++;
            else
                curr_dir += 3;
        }
        else
            sec_p = arr[1];
    }

    printf("curr_dir is {%d}, dip_p is {%c}, sec_p is {%c}, ", curr_dir, dir_p, sec_p);

    return 0;
}
