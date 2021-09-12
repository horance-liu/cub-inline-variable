#ifndef BF40F857_4067_40AD_8A2C_2403871CA8AB
#define BF40F857_4067_40AD_8A2C_2403871CA8AB

#include <type_traits>
#include "cub/identity.h"

#ifdef __cpp_inline_variables

#if defined(__clang__)
# define CUB_EXTERN_DECL(type, name) \
  extern const ::cub::identity_t<type> name;
#else
# define CUB_EXTERN_DECL(type, name)
#endif

#define CUB_INLINE_CONSTEXPR(type, name, init) \
  CUB_EXTERN_DECL(type, name)                  \
  inline constexpr ::cub::identity_t<type> name = init

#else // __cpp_inline_variables

#define CUB_INLINE_CONSTEXPR(type, name, init)                \
  template <class /* CubInternalDummy */ = void>              \
  struct CubInlineVariableHolder##name {                      \
    static constexpr ::cub::identity_t<type> inst = init;     \
  };                                                          \
                                                              \
  template <class CubInternalDummy>                           \
  constexpr ::cub::identity_t<type>                           \
      CubInlineVariableHolder##name<CubInternalDummy>::inst;  \
                                                              \
  static constexpr const ::cub::identity_t<type>&             \
      name = /* NOLINT */                                     \
      CubInlineVariableHolder##name<>::inst;                  \
  static_assert(sizeof(void (*)(decltype(name))) != 0,        \
                "exclude unused variable warnings.")

#endif  // __cpp_inline_variables

#endif /* BF40F857_4067_40AD_8A2C_2403871CA8AB */
