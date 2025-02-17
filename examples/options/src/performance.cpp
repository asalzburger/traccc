/** TRACCC library, part of the ACTS project (R&D line)
 *
 * (c) 2022-2024 CERN for the benefit of the ACTS project
 *
 * Mozilla Public License Version 2.0
 */

// Local include(s).
#include "traccc/options/performance.hpp"

#include "traccc/examples/utils/printable.hpp"

// System include(s).
#include <iostream>

namespace traccc::opts {

performance::performance() : interface("Performance Measurement Options") {

    m_desc.add_options()("check-performance",
                         boost::program_options::bool_switch(&run),
                         "Run performance checks");
}

std::unique_ptr<configuration_printable> performance::as_printable() const {
    std::unique_ptr<configuration_printable> cat =
        std::make_unique<configuration_category>(
            "Performance measurement options");

    dynamic_cast<configuration_category &>(*cat).add_child(
        std::make_unique<configuration_kv_pair>("Run performance checks",
                                                run ? "yes" : "no"));

    return cat;
}
}  // namespace traccc::opts
