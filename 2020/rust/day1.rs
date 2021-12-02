use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}

fn main() {
    if let Ok(lines) = read_lines("./input") {
        for line1 in lines {
            if let Ok(number) = line1 {
                if let Ok(lines) = read_lines("./input") {
                    for line2 in lines {
                        if let Ok (nextnumber) = line2 {
                            if let Ok(lines) = read_lines("./input") {
                                for line3 in lines {
                                    if let Ok (nextnextnumber) = line3 {
                                        let n = number.parse::<i32>().unwrap(); 
                                        let nn = nextnumber.parse::<i32>().unwrap();
                                        let nnn = nextnextnumber.parse::<i32>().unwrap();

                                        let sum = n+nn+nnn;
                                        if sum == 2020 {
                                            let result = n*nn*nnn;
                                            println!("{}", result);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
