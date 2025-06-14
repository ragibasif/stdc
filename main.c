#define F_MEMORY_DEBUG /* turns on the memory debugging system */
#include "internal_debug.h"
#include "log.h"

int main(int argc, char **argv) {
    INFO("Hello %s %d", "Info", 1000);
    DEBUG("Hello %s %d", "debug", 1000);
    TRACE("Hello %s %d", "trace", 1000);
    WARN("Hello %s %d", "warn", 1000);
    ERROR("Hello %s %d", "error", 1000);
    FATAL("Hello %s %d", "fatal", 1000);

#ifdef F_MEMORY_DEBUG
    f_debug_memory_init(NULL, NULL, NULL);
    f_debug_mem_print(0);
    f_debug_mem_reset();
#endif // F_MEMORY_DEBUG

    return 0;
}
