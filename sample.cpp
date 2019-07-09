#include <iostream>
#include "gromacs/fileio/xtcio.h"

using namespace std;
int main (int argc, char** argv)
{

        t_fileio* fi = open_xtc(argv[1], "r");

        int n;

        gmx_int64_t step;

        real time;
        real prec;

        matrix box;

        rvec *x;

        gmx_bool bOK;

        // 原子数もここでゲット
        read_first_xtc(fi, &n, &step, &time, box, &x, &prec, &bOK);
        cout << "REMARK natom = " <<  n << '\n';
        read_next_xtc(fi, n, &step, &time, box, x, &prec, &bOK);
        cout << "Time: " << time << '\n';
        cout << "Step: " << step << '\n';
        cout << "Prec: " << prec << '\n';
        cout << "boxx: " << box[0][0] << '\n';
        cout << "boxy: " << box[1][1] << '\n';
        cout << "boxz: " << box[2][2] << '\n';
        cout << x[0][0] << '\n';
        cout << x[0][1] << '\n';
        cout << x[0][2] << '\n';
        cout << x[1][0] << '\n';
        cout << x[1][1] << '\n';
        cout << x[1][2] << '\n';

        close_xtc(fi);
}
