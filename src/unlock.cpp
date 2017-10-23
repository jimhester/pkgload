#include <Rcpp.h>
using namespace Rcpp;

/* This is taken from envir.c in the R 2.15.1 source
https://github.com/SurajGupta/r-source/blob/master/src/main/envir.c
*/
#define FRAME_LOCK_MASK (1 << 14)
#define FRAME_IS_LOCKED(e) (ENVFLAGS(e) & FRAME_LOCK_MASK)
#define UNLOCK_FRAME(e) SET_ENVFLAGS(e, ENVFLAGS(e) & (~FRAME_LOCK_MASK))

// [[Rcpp::export]]
bool unlock_environment(Environment env) {
  UNLOCK_FRAME(env);
  return FRAME_IS_LOCKED(env) == 0;
}
