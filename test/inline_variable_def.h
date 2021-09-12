#ifndef EA93BA19_DABB_4DB0_965E_265FCE0C237A
#define EA93BA19_DABB_4DB0_965E_265FCE0C237A

#include "cub/inline_variable.h"

namespace cub {
namespace inline_variable_testing {

struct Foo {
  int value = 5;
};

CUB_INLINE_CONSTEXPR(Foo, inline_variable_foo, {});
CUB_INLINE_CONSTEXPR(Foo, other_inline_variable_foo, {});

CUB_INLINE_CONSTEXPR(int, inline_variable_int, 5);
CUB_INLINE_CONSTEXPR(int, other_inline_variable_int, 5);

CUB_INLINE_CONSTEXPR(void(*)(), inline_variable_fun_ptr, nullptr);

const Foo& get_foo_a();
const Foo& get_foo_b();

const int& get_int_a();
const int& get_int_b();

}  // namespace inline_variable_testing
}  // namespace cub

#endif /* EA93BA19_DABB_4DB0_965E_265FCE0C237A */
