/* top level output format are slightly different than expressions (they have to be `structure_item`s). We'd
   like to reuse the statementMapper's logic as much as possible though; so we use it, destructure to
   get what we want, then re-wrap for top level output. */
let mapper: (Types.state, Parser_flow.Ast.Statement.t) => Types.state =
  (state, statement) => {
    let state = HandlePlainStatement.mapper(state, statement);
    state;
  };
