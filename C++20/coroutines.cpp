#include <coroutine>
#include <iostream>

struct Generator {
    struct promise_type {
        int current_value;
        std::suspend_always yield_value(int value) {
            current_value = value;
            return {};
        }
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        Generator get_return_object() { return Generator{this}; }
        void return_void() {}
        void unhandled_exception() { std::exit(1); }
    };

    promise_type* p;
    Generator(promise_type* p) : p(p) {}
    bool move_next() { return !p->current_value; }
    int current_value() const { return p->current_value; }
};

Generator counter() {
    for (int i = 0; i < 5; ++i) {
        co_yield i;
    }
}

int main() {
    auto gen = counter();
    while (gen.move_next()) {
        std::cout << gen.current_value() << " ";  // Output: 0 1 2 3 4
    }
    return 0;
}

