/*

    Copyright 2016 Carl Lei

    This file is part of Bamboo Shoot 3.

    Bamboo Shoot 3 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Bamboo Shoot 3 is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Bamboo Shoot 3.  If not, see <http://www.gnu.org/licenses/>.

    Carl Lei <xecycle@gmail.com>

*/

#include "checker.hh"

int main()
{
  // serialize
  check_serialize(std::make_pair('a', 'b'), "ab");

  // parse
  check_parse("ab", std::make_pair('a', 'b'));

  // early eof
  check_early_eof<std::pair<char, char>>("");
  check_early_eof<std::pair<char, char>>("a");

  // can parse const
  {
    std::istringstream in("ab");
    pbss::parse<const std::pair<char, char>>(in);
  }

  // do not consume extra bytes
  check_extra_consume<std::pair<char, char>>("ab");

  return 0;
}
