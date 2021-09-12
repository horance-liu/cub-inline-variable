#ifndef E95F7180_60FA_419C_B61B_1AEF4A0C1EF5
#define E95F7180_60FA_419C_B61B_1AEF4A0C1EF5

namespace cub {

template <typename T>
struct identity {
  typedef T type;
};

template <typename T>
using identity_t = typename identity<T>::type;

} // cub

#endif /* E95F7180_60FA_419C_B61B_1AEF4A0C1EF5 */
