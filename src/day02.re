let solve = (input) =>
  Js.String.split("\n", input)
  |> Array.to_list
  |> List.fold_left(
       (acc, item) => {
         let values =
           Js.String.splitByRe([%bs.re "/\\s+/"], item) |> Array.to_list |> List.map(int_of_string);
         acc + (List.fold_left(max, 0, values) - List.fold_left(min, max_int, values))
       },
       0
     );
