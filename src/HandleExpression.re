let rec mapper: (Types.state, Parser_flow.Ast.Expression.t) => Types.state =
  (state, (_, expression)) =>
    switch (expression) {
    | Literal(lit) => HandleLiteral.h(state, lit)
    | Call({callee: (_, callee), arguments}) =>
      switch (callee) {
      | Identifier((_, name)) =>
        let statesFromArgs =
          arguments
          |> List.map(argument =>
               switch (argument) {
               | Parser_flow.Ast.Expression.Expression(e) => mapper(state, e)
               | Spread((_, _)) => state /* Spread operator inside function call, what to do... */
               }
             );
        {
          ...state,
          outputStatements: [Types.ExternalModule, ...state.outputStatements],
        };
      | _ => state
      }
    | This
    | Super
    | Array(_)
    | Object(_)
    | Function(_)
    | ArrowFunction(_)
    | Sequence(_)
    | Unary(_)
    | Binary(_)
    | Assignment(_)
    | Update(_)
    | Logical(_)
    | Conditional(_)
    | New(_)
    | Member(_)
    | Yield(_)
    | Comprehension(_)
    | Generator(_)
    | Identifier(_)
    | TemplateLiteral(_)
    | TaggedTemplate(_)
    | JSXElement(_)
    | Class(_)
    | TypeCast(_)
    | MetaProperty(_) => state
    };