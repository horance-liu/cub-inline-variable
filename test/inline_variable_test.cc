#include "cctest/cctest.h"
#include "inline_variable_def.h"

namespace cub {
namespace inline_variable_testing {
namespace {

FIXTURE(InlineVariableTest) {

    TEST("inline constexpr") {
        static_assert(inline_variable_foo.value == 5, "");
        static_assert(other_inline_variable_foo.value == 5, "");
        static_assert(inline_variable_int == 5, "");
        static_assert(other_inline_variable_int == 5, "");
    }

    TEST("default constructed for identity_equality") {
        ASSERT_EQ(get_foo_a().value, 5);
        ASSERT_EQ(get_foo_b().value, 5);
        ASSERT_EQ(&get_foo_a(), &get_foo_b());
    }

    TEST("default constructed for inequality") {
        ASSERT_NE(&inline_variable_foo, &other_inline_variable_foo);
    }

    TEST("initialized identity for Equality") {
        ASSERT_EQ(get_int_a(), 5);
        ASSERT_EQ(get_int_b(), 5);
        ASSERT_EQ(&get_int_a(), &get_int_b());
    }

    TEST("initialized identity for inequality") {
        ASSERT_NE(&inline_variable_int, &other_inline_variable_int);
    }

    TEST("inline variable for function pointer") {
        static_assert(
            std::is_same<void(*)(),
                        std::decay<decltype(inline_variable_fun_ptr)>::type>::value,
            "");
    }

};

} // namespace
}  // namespace inline_variable_testing
}  // namespace cub