let () =
  /* Ocaml  */
  /* if (Array.length(Sys.argv) != 2) { */
  /* Js */
  if (Array.length(Sys.argv) != 3) {
    raise(
      Invalid_argument(
        "Please provide as argument the JS file to convert over.",
      ),
    );
  } else {
    /* OCaml */
    /* let file = Sys.argv[1]; */
    /* Js */
    let file = Sys.argv[2];
    let parse_options =
      Some(
        Parser_env.{
          /***
           * Always parse ES proposal syntax. The user-facing config option to
           * ignore/warn/enable them is handled during inference so that a clean error
           * can be surfaced (rather than a more cryptic parse error).
           */
          esproposal_class_instance_fields: true,
          esproposal_class_static_fields: true,
          esproposal_decorators: true,
          esproposal_export_star_as: true,
          types: true,
          use_strict: false,
        },
      );
    /* OCaml */
    /* let content = cat(file); */
    /* Js */
    let content = Node.Fs.readFileAsUtf8Sync(file);
    let (ast, _) =
      Parser_flow.program_file(
        ~fail=false,
        ~parse_options,
        content,
        Some(Loc.SourceFile(file)),
      );
    let (_, statements, _) = ast;
    /* OCaml only */
    /* output_string(stdout, Config.ast_impl_magic_number); */
    /* OCaml */
    /* output_value(stdout, file); */
    /* Js */
    /* Js.log(Js.Json.stringifyAny(file)); */
    let result: Parsetree.structure =
      statements
      |> List.fold_left(
           (accState, statement) =>
             HandleTopStatement.mapper(accState, statement),
           {identifiers: [], outputStatements: []},
         )
      |> (resultingState => resultingState.outputStatements)
      |> IrTransformer.transform;
    ();
    /* OCaml */
    /* output_value(stdout, result); */
    /* Js */
    /* Js.log(Js.Json.stringifyAny(result)); */
  };