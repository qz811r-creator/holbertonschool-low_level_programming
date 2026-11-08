# Green Efficiency & Benchmarking Analysis Report

## Measurement Methodology
In this lab, performance metrics were gathered using C standard library timing functions under strict compilation flags (`-Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long`). Timing instrumentation was implemented using `clock()` from `<time.h>`, measuring execution time in CPU clock ticks and converting it to wall-clock seconds via `CLOCKS_PER_SEC`.

Three specific benchmarks were performed:
1. **Baseline Loop Execution (Task 0):** A loop executing $100,000,000$ iterations was measured across three consecutive runs, recording execution times of $0.210754$s, $0.209453$s, and $0.216362$s (averaging ~$0.212190$s).
2. **Algorithmic Comparison (Task 1):** Two implementations counting even numbers in a dataset of $50,000$ elements were evaluated. The Naive algorithm ($O(N^2)$) took an average of $2.319354$ seconds ($2.308583$s, $2.298988$s, $2.350490$s), while the Single-pass algorithm ($O(N)$) averaged $0.000100$ seconds ($0.000092$s, $0.000106$s, $0.000102$s).
3. **Multi-Phase Instrumentation (Task 2):** A multi-phase pipeline measured sub-component execution times over $50,000$ elements: `BUILD_DATA` took $0.000184$s, `PROCESS` took $0.000185$s, and `REDUCE` took $0.000145$s, yielding a `TOTAL` execution time of $0.000516$s.

## Observed Performance Differences
The empirical results highlight a stark contrast between algorithmic design choices. In Task 1, comparing the $O(N^2)$ Naive approach ($2.319354$s average) to the $O(N)$ Single-pass approach ($0.000100$s average) demonstrates a relative slowdown factor of approximately **23,194 times**. 

In Task 2, multi-phase instrumentation showed balanced execution across phases: `BUILD_DATA` ($35.66\%$), `PROCESS` ($35.85\%$), and `REDUCE` ($28.10\%$). The combined execution time of the phases ($0.000514$s) remains bounded within the total wall-clock time ($0.000516$s), validating the consistency of the measurement boundaries.

Small variances were observed across runs in Task 0 ($0.209453$s to $0.216362$s), illustrating inherent operating system context switching and CPU scheduling noise during baseline execution.

## Relation Between Runtime and Energy Consumption
In modern computing infrastructure, energy consumption ($E$) is directly proportional to the dynamic power drawn by the hardware ($P$) multiplied by execution time ($T$), expressed as $E = P \times T$. Since CPU power draw remains high during active processing cycles, reducing execution time directly lowers total energy consumption.

The Naive algorithm in Task 1 spent $2.319354$ seconds executing unnecessary inner-loop iterations, retaining high CPU utilization. Conversely, the Single-pass algorithm accomplished the identical computational outcome in $0.000100$ seconds. By achieving a ~23,194x reduction in runtime, energy consumption for that computational workload is scaled down by a comparable magnitude, illustrating that algorithmic optimization is a primary driver of sustainable, green software development.

## Limitations of the Experiment
While `clock()` provides a standard portable interface, several key limitations exist in this measurement setup:
1. **Measurement Resolution & System Overhead:** `clock()` measures CPU process time rather than precise elapsed wall-clock time, which can introduce noise from context switches and OS scheduling.
2. **Absence of Optimization Flags:** Tests were compiled without compiler optimization flags (such as `-O2` or `-O3`), which means the runtime does not reflect optimized production binaries where loop unrolling or vectorization might occur.
3. **Hardware & Power Variations:** The experiment did not directly measure dynamic power draw (e.g., via RAPL or hardware wattmeters), relying on runtime as a proxy metric for energy efficiency.

## Practical Engineering Takeaway
The evidence gathered in this lab proves that optimizing algorithms ($O(N^2) \to O(N)$) yields far greater efficiency gains than micro-optimizations. Engineers must prioritize structural efficiency before relying on compiler flags or dynamic hardware scaling. Profiling phase boundaries before optimizing ensures development effort is focused directly on computational bottlenecks.
