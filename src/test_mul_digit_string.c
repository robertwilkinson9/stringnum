#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void call_mul_digit_string(const int, const int *, const char **, const char **);
int mul_digit_string(const int, const char *, char **);

int main()
{
  const int scalars[4] = {9, 7, 1, 0};
  const char *numeric_input[4] = {
    "75415123591065981965009485944457939790477550112631613307953910218357656560185790391063809273661832958588846804708867683435301180538880000000000000000000000",
    "848420140399492297106356716875151822642872438767105649714481489956523636302090141899467854328695620784124526552974761438647138281062400000000000000000000000",
    "75415123591065981965009485944457939790477550112631613307953910218357656560185790391063809273661832958588846804708867683435301180538880000000000000000000000",
    "75415123591065981965009485944457939790477550112631613307953910218357656560185790391063809273661832958588846804708867683435301180538880000000000000000000000"
  };

  const char *numeric_output[4] = {
    "678736112319593837685085373500121458114297951013684519771585191965218909041672113519574283462956496627299621242379809150917710624849920000000000000000000000",
    "5938940982796446079744497018126062758500107071369739548001370429695665454114630993296274980300869345488871685870823330070529967967436800000000000000000000000",
    "75415123591065981965009485944457939790477550112631613307953910218357656560185790391063809273661832958588846804708867683435301180538880000000000000000000000",
    "0"
  };

  int i;
  for (i = 0; i < 4; ++i)
    call_mul_digit_string(i, scalars, numeric_input, numeric_output);

  return(0);
}

void call_mul_digit_string(const int index, const int *scalars, const char **numeric_input, const char **numeric_output)
{
  int a = scalars[index];
  char *b = (char *) calloc(strlen(numeric_input[index]) + 1, sizeof(char));
  strncpy(b, numeric_input[index], strlen(numeric_input[index]));
  char *c = (char *) calloc(strlen(b) + 1, sizeof(char));

  mul_digit_string(a, b, &c);
  if (strncmp(c, numeric_output[index], strlen(numeric_output[index])))
    printf("%d * %s is %s and should be %s\n", a, b, c, numeric_output[index]);

  free(c);
  free(b);
}