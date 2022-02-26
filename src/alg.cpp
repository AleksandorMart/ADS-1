// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
 uint64_t i;
 for(i = 2; i <= value/2; i++){
  if (value % i == 0){
   return false;
  }
 }
 return true;
}

uint64_t nPrime(uint64_t n) {
 uint64_t count, pr;
 pr = 2;
 count = 1;
 if (checkPrime(n)){
  while (true){
   if (n == pr){
    return count;
   }
   pr++;
   if (checkPrime(pr)) count++;
  }
 }
 return 0;
}

uint64_t nextPrime(uint64_t value) {
 uint64_t pr;
 pr = value;
 while (true){
   pr++;
   if (checkPrime(pr)) return pr;
 }
}

uint64_t sumPrime(uint64_t hbound) {
 if (hbound == 1 || hbound == 0) return 0;
 hbound--;
 if (checkPrime(hbound)){
  return (hbound + sumPrime(hbound));
 }
 else if (!checkPrime(hbound)){
  return sumPrime(hbound);
 }
}
