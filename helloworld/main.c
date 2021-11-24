#include "postgres.h"

PG_MODULE_MAGIC;

void _PG_init(void);
void _PG_fini(void);

Datum pg_all_queries(PG_FUNCNAME_ARGS);
PG_FUNCNAME_INFO_V1(pg_all_queries);

// callback function
static void process_utility(
    PlannedStmt *pstmt, 
    const char *queryString, 
    ProcessUtilityContext context,
    ParamListInfo params,
    QueryEnvironment *queryEnv,
    DestReceiver *dest,       
    char *completionTag
    );


void _PG_init(void)
{
    ProcessUtility_hook = process_utility;
}

void _PG_Fini(void)
{

}

static void process_utility(
    PlannedStmt *pstmt, 
    const char *queryString, 
    ProcessUtilityContext context,
    ParamListInfo params,
    QueryEnvironment *queryEnv,
    DestReceiver *dest,       
    char *completionTag
){
    standard_ProcessUtility(
        pstmt,  &nbsp;
        queryString,  &nbsp;
        context,  &nbsp;
        params,  &nbsp;
        queryEnv,  &nbsp;
        dest, 
        completionTag)
}

Datum pg_all_queries(PG_FUNCTION_ARGS)
{
    tupstore = tuplestore_begin_heap(true, false, work_mem);
    values[0] = CStringGetTextDatum(query);
    values[1] = CStringGetTextDatum(pid);
    tuplestore_donestoring(tupstore);
    return (Datum) 0;
}