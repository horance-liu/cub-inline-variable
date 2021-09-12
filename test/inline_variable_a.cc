#include "inline_variable_def.h"

namespace cub {
namespace inline_variable_testing {

const Foo& get_foo_a() { 
    return inline_variable_foo; 
}

const int& get_int_a() { 
    return inline_variable_int; 
}

}  // namespace inline_variable_testing
}  // namespace cub