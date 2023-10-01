#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    int tic;

    if (argc!=2)
    {
        fprintf(2, "CHYBA\n");
        exit(-1);
    }

    tic = atoi(argv[1]);

    sleep(tic);

    exit(0);
}
