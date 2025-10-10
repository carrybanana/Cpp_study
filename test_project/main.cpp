#include <vector>
#include <string>
#include <print>          // C++23: std::print / std::println
#include <ranges>         // for std::views::enumerate
#include <optional>       // for std::optional monadic ops

// C++23: std::optional 的 "monadic" 操作（transform, and_then, or_else）
void test_optional_monadic() {
    std::optional<int> opt = 42;

    auto result = opt
        .transform([](int x) { return x * 2; })
        .and_then([](int x) -> std::optional<std::string> {
            return x > 50 ? std::optional{"Large: " + std::to_string(x)} : std::nullopt;
        })
        .or_else([]() -> std::optional<std::string> {
            return "Too small";
        });
    std::println("Optional result: {}", result.value_or("none"));
}

// C++23: std::views::enumerate
void test_enumerate() {
    std::vector<std::string> fruits = {"apple", "banana", "cherry"};

    for (auto [index, value] : fruits | std::views::enumerate) {
        std::println("{}: {}", index, value);
    }
}

// C++23: if consteval
consteval int compile_time_square(int n) {
    return n*n;
    // if consteval {
    //     return n * n;
    // } else {
    //     return 0; // unreachable in consteval function
    // }
}

void test_print_format() {
    std::print("Hello {}! Pi ≈ {:.2f}\n", "C++23", 3.14159);
}

int main() {
    std::println("🚀 Starting C++23 feature test...");

    test_optional_monadic();
    test_enumerate();

    constexpr int sq = compile_time_square(5);
    std::println("5² at compile-time: {}", sq);

    test_print_format();

    std::println("✅ C++23 tests completed.");
    return 0;
}
