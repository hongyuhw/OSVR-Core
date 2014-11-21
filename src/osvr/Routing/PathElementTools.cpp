/** @file
    @brief Implementation

    @date 2014

    @author
    Ryan Pavlik
    <ryan@sensics.com>
    <http://sensics.com>
*/

// Copyright 2014 Sensics, Inc.
//
// All rights reserved.
//
// (Final version intended to be licensed under
// the Apache License, Version 2.0)

// Internal Includes
#include <osvr/Routing/PathElementTypes.h>
#include <boost/variant/static_visitor.hpp>
#include <boost/variant/apply_visitor.hpp>

// Library/third-party includes
// - none

// Standard includes
// - none

namespace osvr {
namespace routing {
    namespace elements {
        using boost::static_visitor;
        using boost::apply_visitor;
        namespace {
            class TypeNameVisitor : public static_visitor<const char *> {
              public:
#define OSVR_ROUTING_TYPENAME_HANDLER(CLASS)                                   \
    const char *operator()(CLASS const &) const { return #CLASS; }

                OSVR_ROUTING_TYPENAME_HANDLER(NullElement)
                OSVR_ROUTING_TYPENAME_HANDLER(PluginElement)
                OSVR_ROUTING_TYPENAME_HANDLER(DeviceElement)
                OSVR_ROUTING_TYPENAME_HANDLER(InterfaceElement)
                OSVR_ROUTING_TYPENAME_HANDLER(SensorElement)
                OSVR_ROUTING_TYPENAME_HANDLER(PhysicalAssociationElement)
                OSVR_ROUTING_TYPENAME_HANDLER(LogicalElement)
#undef OSVR_ROUTING_TYPENAME_HANDLER
            };
        } // namespace
        const char *getTypeName(PathElement const &elt) {
            return boost::apply_visitor(TypeNameVisitor(), elt);
        }
    } // namespace elements
} // namespace routing
} // namespace osvr