#pragma once

#define STATIC_ASSERT(COND) typedef char static_assertion_##__LINE__[(!!(COND))*2-1]
