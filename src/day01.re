let explode = (s) => {
  let rec exp = (index, list) =>
    index < 0 ? list : exp(index - 1, [Char.escaped(s.[index]), ...list]);
  exp(String.length(s) - 1, [])
};

let solve = (string) => {
  let list = explode(string) |> List.map((item) => Some(int_of_string(item)));
  List.fold_left2(
    (acc, a1, a2) =>
      switch (a1, a2) {
      | (Some(a1), Some(a2)) when a1 === a2 => acc + a1
      | _ => acc
      },
    0,
    List.append(list, [List.hd(list)]),
    [None, ...list]
  )
};
