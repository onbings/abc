#include "lib/abc_lib.h"
#include <argh.h> //https://github.com/adishavit/argh
#include <bofstd/boffs.h>
#include <bofstd/bofstd.h>
#include <cstdio>

int main(int argc, char *argv[]) {
  printf("Hello world !\n");
  printf("Sum(1,2) returns %d\n", sum(1, 2));
  argh::parser cmdl(argv);
  if (cmdl[{"-v", "--verbose"}])
    printf("Verbose, I am.\n");
  BOFERR Sts_E;
  BOF::BOFSTDPARAM StdParam_X;
  std::string Cwd_S;
  Sts_E = BOF::Bof_Initialize(StdParam_X);
  BOF_ASSERT(Sts_E == BOF_ERR_NO_ERROR);
  BOF::Bof_GetCurrentDirectory(Cwd_S);
  printf("\nPwd %s\nRunning BofStd V %s on %s under %s\n", Cwd_S.c_str(),
         StdParam_X.Version_S.c_str(), StdParam_X.ComputerName_S.c_str(),
         StdParam_X.OsName_S.c_str());

  return 0;
}
