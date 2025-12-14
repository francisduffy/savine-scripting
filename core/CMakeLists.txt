add_library(scripting_core STATIC)

target_sources(scripting_core
    PRIVATE
        scripting/Nodes.cpp
        scripting/Parser.cpp
        utilities/functDomain.cpp

    PUBLIC
        FILE_SET scripting_core_HEADERS
        TYPE HEADERS
        FILES
            scripting/ConstCondProc.h
            scripting/Debugger.h
            scripting/DomainProc.h
            scripting/Evaluator.h
            scripting/Events.h
            scripting/FuzzyEval.h
            scripting/IfProc.h
            scripting/Model.h
            scripting/Nodes.h
            scripting/Parser.h
            scripting/Scenarios.h
            scripting/VarIndexer.h
            scripting/Visitor.h
            utilities/basicRanGen.h
            utilities/functDomain.h
            utilities/gaussians.h
            utilities/matrix.h
            utilities/quickStack.h
)
