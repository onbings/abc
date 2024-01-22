#include <cstdio>
// 1 #include "lib/abc_lib.h"
// 2 #include <argh.h>  //https://github.com/adishavit/argh
// 3 #include <bofstd/bofstd.h>
// 3 #include <bofstd/boffs.h>

int main(int argc, char *argv[]) {
  printf("Hello world !\n");
  // 1  printf("Sum(1,2) returns %d\n", sum(1, 2));
  // 2 argh::parser cmdl(argv);
  // 2  if (cmdl[{ "-v", "--verbose" }]) printf("Verbose, I am.\n");

  // 3 BOFERR Sts_E;
  // 3 BOF::BOFSTDPARAM StdParam_X;
  // 3 std::string Cwd_S;

  // 3 Sts_E = BOF::Bof_Initialize(StdParam_X);
  // 3 BOF_ASSERT(Sts_E == BOF_ERR_NO_ERROR);
  // 3 BOF::Bof_GetCurrentDirectory(Cwd_S);
  // 3 printf("\nPwd %s\nRunning BofStd V %s on %s under %s\n", Cwd_S.c_str(),
  // StdParam_X.Version_S.c_str(), StdParam_X.ComputerName_S.c_str(),
  // StdParam_X.OsName_S.c_str());

  return 0;
}
