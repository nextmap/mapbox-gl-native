#pragma once

#include <mbgl/util/noncopyable.hpp>

#include <string>

namespace mbgl {

namespace gfx {
class Context;
} // namespace gfx

namespace gl {

#ifndef NDEBUG

class DebugGroup : private util::noncopyable {
public:
    DebugGroup(const gfx::Context&, const std::string&);
    ~DebugGroup();

private:
    const gfx::Context& context;
};

#define __MBGL_DEBUG_GROUP_NAME2(counter) __MBGL_DEBUG_GROUP_##counter
#define __MBGL_DEBUG_GROUP_NAME(counter) __MBGL_DEBUG_GROUP_NAME2(counter)
#define MBGL_DEBUG_GROUP(context, name) const ::mbgl::gl::DebugGroup __MBGL_DEBUG_GROUP_NAME(__LINE__)(context, name);

#else

#define MBGL_DEBUG_GROUP(context, name)

#endif

} // namespace gl
} // namespace mbgl
