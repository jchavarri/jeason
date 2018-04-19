let h: (Types.state, Parser_flow.Ast.Literal.t) => Types.state =
  (state, {value, raw}) =>
    switch (value) {
    | String(s) =>
      Js.log(s);
      state;
    | Boolean(_)
    | Null
    | Number(_)
    | RegExp(_) => state
    };