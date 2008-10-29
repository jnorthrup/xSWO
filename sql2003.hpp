#define BOOST_SPIRIT_DEBUG

#include <iostream>
#include <ostream>
#include <string>
#include <boost/spirit/core.hpp>
#include <boost/spirit/utility/confix.hpp>
#include <boost/spirit/utility/chset.hpp>
#include <boost/spirit/utility/escape_char.hpp>

using namespace boost::spirit;

struct sql2003_parser : public grammar<sql2003_parser>
{
    template<typename ScannerT>
    struct definition
    {
        definition(sql2003_parser const& /*self*/)
        {
			
			
			SQLTerminalCharacter = SQLTerminalCharacter;;;
			SQLTerminalCharacter= alpha_p
			
			| digit_p
			
			| SqlSpecialCharacters
			;;
			alpha_p = upper_p  
			| lower_p;;;  
			SqlSpecialCharacters		= chset_p( "\"%&'()*+,-./:;<^=>? {}_|[]")|blank_p	 ;;;
			//SQLSpecialCharacter = chset_p( "\"%&'()*+,-./:;<^=>? {}_|[]")	 ;;;
			
			
			Token = NondelimiterToken  
			| DelimiterToken;;;
			NondelimiterToken = RegularIdentifier  
			| KeyWord  
			| UnsignedNumericLiteral  
			| NationalCharacterStringLiteral  
			| BitStringLiteral  
			| HexStringLiteral  
			| LargeObjectLengthToken  
			| Multiplier;;;
			RegularIdentifier = IdentifierBody;;;
			IdentifierBody = (IdentifierStart >> *IdentifierPart);;;
			IdentifierPart = IdentifierStart  
			| IdentifierExtend;;;
			IdentifierStart = nothing_p;;;
			IdentifierExtend = nothing_p;;;
			LargeObjectLengthToken = +digit_p >> Multiplier;;;
			Multiplier =ch_p('K')  
			|('M')  
			|('G');;;
			UnicodeDelimitedIdentifier = (U  >> '&'   >> '"'  >> +UnicodeDelimiterBody  >> '"'  >> !(str_p("ESCAPE")) >> EscapeCharacter);;;
			UnicodeDelimiterBody = +UnicodeIdentifierPart;;;
			UnicodeIdentifierPart = DelimitedIdentifierPart  
			| UnicodeEscapeValue;;;
			UnicodeEscapeValue = Unicode4DigitEscapeValue  
			| Unicode6DigitEscapeValue;;;
			Unicode4DigitEscapeValue = EscapeCharacter >> xdigit_p >> xdigit_p >> xdigit_p >> xdigit_p;;;
			Unicode6DigitEscapeValue = EscapeCharacter  >> '+'  >> xdigit_p >> xdigit_p >> xdigit_p >> xdigit_p >> xdigit_p >> xdigit_p;;;
			EscapeCharacter = nothing_p;;;
			NondoublequoteCharacter = nothing_p;;;
			DoublequoteSymbol = str_p("\"\"");;;
			DelimiterToken = CharacterStringLiteral  
			| DateString  
			| TimeString  
			| TimestampString  
			| IntervalString  
			| DelimitedIdentifier  
			| UnicodeDelimitedIdentifier  
			| SqlSpecialCharacters		 
			| NotEqualsOperator  
			| GreaterThanOrEqualsOperator  
			| LessThanOrEqualsOperator  
			| ConcatenationOperator  
			| RightArrow  
			| LeftBracketTrigraph  
			| RightBracketTrigraph  
			| DoubleColon  
			| DoublePeriod;;;
			NotEqualsOperator = ch_p('<')  >> '>' ;;;
			GreaterThanOrEqualsOperator = ch_p('>')  >> '=' ;;;
			LessThanOrEqualsOperator = ch_p('<')  >> '=' ;;;
			ConcatenationOperator = ch_p('|')  >> '|' ;;;
			RightArrow = str_p("->");;;
			DoubleColon = str_p("::");;;
			DoublePeriod = str_p("..");;;
			
			Separator = +(Comment  
						  | WhiteSpace);;;
			Comment = SimpleComment  
			| BracketedComment;;;
			SimpleComment = (SimpleCommentIntroducer >> *CommentCharacter >> eol_p);;;
			SimpleCommentIntroducer = (str_p("--")>>*ch_p('-'));;;
			BracketedComment = BracketedCommentIntroducer >> BracketedCommentContents >> BracketedCommentTerminator;;;
			BracketedCommentIntroducer = Slash  >> '*' ;;;
			BracketedCommentTerminator = ch_p('*') >> Slash;;;
			BracketedCommentContents = *((CommentCharacter  
										  | Separator));;;
			CommentCharacter = NonquoteCharacter  
			| ch_p('\'');;;
 			KeyWord = ReservedWord  
			| NonReservedWord;;;
			NonReservedWord =ch_p('A')  
			| "ABS"   
			| "ABSOLUTE"   
			| "ACTION"   
			| "ADA"   
			| "ADMIN"   
			| "AFTER"   
			| "ALWAYS"   
			| "ASC"   
			| "ASSERTION"   
			| "ASSIGNMENT"   
			| "ATTRIBUTE"   
			| "ATTRIBUTES"   
			| "AVG"   
			| "BEFORE"   
			| "BERNOULLI"   
			| "BREADTH"   
			|('C')  
			| "CARDINALITY"   
			| "CASCADE"   
			| "CATALOG"   
			| "CATALOG_NAME"   
			| "CEIL"   
			| "CEILING"   
			| "CHAIN"   
			| "CHARACTERISTICS"   
			| "CHARACTERS"   
			| "CHARACTER_LENGTH"   
			| "CHARACTER_SET_CATALOG"   
			| "CHARACTER_SET_NAME"   
			| "CHARACTER_SET_SCHEMA"   
			| "CHAR_LENGTH"   
			| "CHECKED"   
			| "CLASS_ORIGIN"   
			| "COALESCE"   
			| "COBOL"   
			| "CODE_UNITS"   
			| "COLLATION"   
			| "COLLATION_CATALOG"   
			| "COLLATION_NAME"   
			| "COLLATION_SCHEMA"   
			| "COLLECT"   
			| "COLUMN_NAME"   
			| "COMMAND_FUNCTION"   
			| "COMMAND_FUNCTION_CODE"   
			| "COMMITTED"   
			| "CONDITION"   
			| "CONDITION_NUMBER"   
			| "CONNECTION_NAME"   
			| "CONSTRAINTS"   
			| "CONSTRAINT_CATALOG"   
			| "CONSTRAINT_NAME"   
			| "CONSTRAINT_SCHEMA"   
			| "CONSTRUCTORS"   
			| "CONTAINS"   
			| "CONVERT"   
			| "CORR"   
			| "COUNT"   
			| "COVAR_POP"   
			| "COVAR_SAMP"   
			| "CUME_DIST"   
			| "CURRENT_COLLATION"   
			| "CURSOR_NAME"   
			| "DATA"   
			| "DATETIME_INTERVAL_CODE"   
			| "DATETIME_INTERVAL_PRECISION"   
			| "DEFAULTS"   
			| "DEFERRABLE"   
			| "DEFERRED"   
			| "DEFINED"   
			| "DEFINER"   
			| "DEGREE"   
			| "DENSE_RANK"   
			| "DEPTH"   
			| "DERIVED"   
			| "DESC"   
			| "DESCRIPTOR"   
			| "DIAGNOSTICS"   
			| "DISPATCH"   
			| "DOMAIN"   
			| "DYNAMIC_FUNCTION"   
			| "DYNAMIC_FUNCTION_CODE"   
			| "EQUALS"   
			| "EVERY"   
			| "EXCEPTION"   
			| "EXCLUDE"   
			| "EXCLUDING"   
			| "EXP"   
			| "EXTRACT"   
			| "FINAL"   
			| "FIRST"   
			| "FLOOR"   
			| "FOLLOWING"   
			| "FORTRAN"   
			| "FOUND"   
			| "FUSION"   
			|('G')  
			| "GENERAL"   
			| "GO"   
			| "GOTO"   
			| "GRANTED"   
			| "HIERARCHY"   
			| "IMPLEMENTATION"   
			| "INCLUDING"   
			| "INCREMENT"   
			| "INITIALLY"   
			| "INSTANCE"   
			| "INSTANTIABLE"   
			| "INTERSECTION"   
			| "INVOKER"   
			| "ISOLATION"   
			|('K')  
			| "KEY"   
			| "KEY_MEMBER"   
			| "KEY_TYPE"   
			| "LAST"   
			| "LENGTH"   
			| "LEVEL"   
			| "LN"   
			| "LOCATOR"   
			| "LOWER"   
			|('M')  
			| "MAP"   
			| "MATCHED"   
			| "MAX"   
			| "MAXVALUE"   
			| "MESSAGE_LENGTH"   
			| "MESSAGE_OCTET_LENGTH"   
			| "MESSAGE_TEXT"   
			| "MIN"   
			| "MINVALUE"   
			| "MOD"   
			| "MORE"   
			| "MUMPS"   
			| "NAME"   
			| "NAMES"   
			| "NESTING"   
			| "NEXT"   
			| "NORMALIZE"   
			| "NORMALIZED"   
			| "NULLABLE"   
			| "NULLIF"   
			| "NULLS"   
			| "NUMBER"   
			| "OBJECT"   
			| "OCTETS"   
			| "OCTET_LENGTH"   
			| "OPTION"   
			| "OPTIONS"   
			| "ORDERING"   
			| "ORDINALITY"   
			| "OTHERS"   
			| "OVERLAY"   
			| "OVERRIDING"   
			| "PAD"   
			| "PARAMETER_MODE"   
			| "PARAMETER_NAME"   
			| "PARAMETER_ORDINAL_POSITION"   
			| "PARAMETER_SPECIFIC_CATALOG"   
			| "PARAMETER_SPECIFIC_NAME"   
			| "PARAMETER_SPECIFIC_SCHEMA"   
			| "PARTIAL"   
			| "PASCAL"   
			| "PATH"   
			| "PERCENTILE_CONT"   
			| "PERCENTILE_DISC"   
			| "PERCENT_RANK"   
			| "PLACING"   
			| "PLI"   
			| "POSITION"   
			| "POWER"   
			| "PRECEDING"   
			| "PRESERVE"   
			| "PRIOR"   
			| "PRIVILEGES"   
			| "PUBLIC"   
			| "RANK"   
			| "READ"   
			| "REGR_AVGX"   
			| "REGR_AVGY"   
			| "REGR_COUNT"   
			| "REGR_INTERCEPT"   
			| "REGR_R2"   
			| "REGR_SLOPE"   
			| "REGR_SXX"   
			| "REGR_SXY"   
			| "REGR_SXY"   
			| "RELATIVE"   
			| "REPEATABLE"   
			| "RESTART"   
			| "RESULT"   
			| "RETURNED_CARDINALITY"   
			| "RETURNED_LENGTH"   
			| "RETURNED_OCTET_LENGTH"   
			| "RETURNED_SQLSTATE"   
			| "ROLE"   
			| "ROUTINE"   
			| "ROUTINE_CATALOG"   
			| "ROUTINE_NAME"   
			| "ROUTINE_SCHEMA"   
			| "ROW_COUNT"   
			| "ROW_NUMBER"   
			| "SCALE"   
			| "SCHEMA"   
			| "SCHEMA_NAME"   
			| "SCOPE_CATALOG"   
			| "SCOPE_NAME"   
			| "SCOPE_SCHEMA"   
			| "SECTION"   
			| "SECURITY"   
			| "SELF"   
			| "SEQUENCE"   
			| "SERIALIZABLE"   
			| "SERVER_NAME"   
			| "SESSION"   
			| "SETS"   
			| "SIMPLE"   
			| "SIZE"   
			| "SOURCE"   
			| "SPACE"   
			| "SPECIFIC_NAME"   
			| "SQRT"   
			| "STATE"   
			| "STATEMENT"   
			| "STDDEV_POP"   
			| "STDDEV_SAMP"   
			| "STRUCTURE"   
			| "STYLE"   
			| "SUBCLASS_ORIGIN"   
			| "SUBSTRING"   
			| "SUM"   
			| "TABLESAMPLE"   
			| "TABLE_NAME"   
			| "TEMPORARY"   
			| "TIES"   
			| "TOP_LEVEL_COUNT"   
			| "TRANSACTION"   
			| "TRANSACTIONS_COMMITTED"   
			| "TRANSACTIONS_ROLLED_BACK"   
			| "TRANSACTION_ACTIVE"   
			| "TRANSFORM"   
			| "TRANSFORMS"   
			| "TRANSLATE"   
			| "TRIGGER_CATALOG"   
			| "TRIGGER_NAME"   
			| "TRIGGER_SCHEMA"   
			| "TRIM"   
			| "TYPE"   
			| "UNBOUNDED"   
			| "UNCOMMITTED"   
			| "UNDER"   
			| "UNNAMED"   
			| "UPPER"   
			| "USAGE"   
			| "USER_DEFINED_TYPE_CATALOG"   
			| "USER_DEFINED_TYPE_CODE"   
			| "USER_DEFINED_TYPE_NAME"   
			| "USER_DEFINED_TYPE_SCHEMA"   
			| "VAR_POP"   
			| "VAR_SAMP"   
			| "VIEW"   
			| "WIDTH_BUCKET"   
			| "WORK"   
			| "WRITE"   
			| "ZONE" ;;;
			ReservedWord =(str_p("ADD"))  
			| "ALL"   
			| "ALLOCATE"   
			| "ALTER"   
			| "AND"   
			| "ANY"   
			| "ARE"   
			| "ARRAY"   
			| "AS"   
			| "ASENSITIVE"   
			| "ASYMMETRIC"   
			| "AT"   
			| "ATOMIC"   
			| "AUTHORIZATION"   
			| "BEGIN"   
			| "BETWEEN"   
			| "BIGINT"   
			| "BINARY"   
			| "BLOB"   
			| "BOOLEAN"   
			| "BOTH"   
			| "BY"   
			| "CALL"   
			| "CALLED"   
			| "CASCADED"   
			| "CASE"   
			| "CAST"   
			| "CHAR"   
			| "CHARACTER"   
			| "CHECK"   
			| "CLOB"   
			| "CLOSE"   
			| "COLLATE"   
			| "COLUMN"   
			| "COMMIT"   
			| "CONNECT"   
			| "CONSTRAINT"   
			| "CONTINUE"   
			| "CORRESPONDING"   
			| "CREATE"   
			| "CROSS"   
			| "CUBE"   
			| "CURRENT"   
			| "CURRENT_DATE"   
			| "CURRENT_DEFAULT_TRANSFORM_GROUP"   
			| "CURRENT_PATH"   
			| "CURRENT_ROLE"   
			| "CURRENT_TIME"   
			| "CURRENT_TIMESTAMP"   
			| "CURRENT_TRANSFORM_GROUP_FOR_TYPE"   
			| "CURRENT_USER"   
			| "CURSOR"   
			| "CYCLE"   
			| "DATE"   
			| "DAY"   
			| "DEALLOCATE"   
			| "DEC"   
			| "DECIMAL"   
			| "DECLARE"   
			| "DEFAULT"   
			| "DELETE"   
			| "DEREF"   
			| "DESCRIBE"   
			| "DETERMINISTIC"   
			| "DISCONNECT"   
			| "DISTINCT"   
			| "DOUBLE"   
			| "DROP"   
			| "DYNAMIC"   
			| "EACH"   
			| "ELEMENT"   
			| "ELSE"   
			| "END"   
			|  "END-EXEC"
			| "ESCAPE"   
			| "EXCEPT"   
			| "EXEC"   
			| "EXECUTE"   
			| "EXISTS"   
			| "EXTERNAL"   
			| "FALSE"   
			| "FETCH"   
			| "FILTER"   
			| "FLOAT"   
			| "FOR"   
			| "FOREIGN"   
			| "FREE"   
			| "FROM"   
			| "FULL"   
			| "FUNCTION"   
			| "GET"   
			| "GLOBAL"   
			| "GRANT"   
			| "GROUP"   
			| "GROUPING"   
			| "HAVING"   
			| "HOLD"   
			| "HOUR"   
			| "IDENTITY"   
			| "IMMEDIATE"   
			| "IN"   
			| "INDICATOR"   
			| "INNER"   
			| "INOUT"   
			| "INPUT"   
			| "INSENSITIVE"   
			| "INSERT"   
			| "INT"   
			| "INTEGER"   
			| "INTERSECT"   
			| "INTERVAL"   
			| "INTO"   
			| "IS"   
			| "ISOLATION"   
			| "JOIN"   
			| "LANGUAGE"   
			| "LARGE"   
			| "LATERAL"   
			| "LEADING"   
			| "LEFT"   
			| "LIKE"   
			| "LOCAL"   
			| "LOCALTIME"   
			| "LOCALTIMESTAMP"   
			| "MATCH"   
			| "MEMBER"   
			| "MERGE"   
			| "METHOD"   
			| "MINUTE"   
			| "MODIFIES"   
			| "MODULE"   
			| "MONTH"   
			| "MULTISET"   
			| "NATIONAL"   
			| "NATURAL"   
			| "NCHAR"   
			| "NCLOB"   
			| "NEW"   
			| "NO"   
			| "NONE"   
			| "NOT"   
			| "NULL"   
			| "NUMERIC"   
			| "OF"   
			| "OLD"   
			| "ON"   
			| "ONLY"   
			| "OPEN"   
			| "OR"   
			| "ORDER"   
			| "OUT"   
			| "OUTER"   
			| "OUTPUT"   
			| "OVER"   
			| "OVERLAPS"   
			| "PARAMETER"   
			| "PARTITION"   
			| "PRECISION"   
			| "PREPARE"   
			| "PRIMARY"   
			| "PROCEDURE"   
			| "RANGE"   
			| "READS"   
			| "REAL"   
			| "RECURSIVE"   
			| "REF"   
			| "REFERENCES"   
			| "REFERENCING"   
			| "RELEASE"   
			| "RETURN"   
			| "RETURNS"   
			| "REVOKE"   
			| "RIGHT"   
			| "ROLLBACK"   
			| "ROLLUP"   
			| "ROW"   
			| "ROWS"   
			| "SAVEPOINT"   
			| "SCROLL"   
			| "SEARCH"   
			| "SECOND"   
			| "SELECT"   
			| "SENSITIVE"   
			| "SESSION_USER"   
			| "SET"   
			| "SIMILAR"   
			| "SMALLINT"   
			| "SOME"   
			| "SPECIFIC"   
			| "SPECIFICTYPE"   
			| "SQL"   
			| "SQLEXCEPTION"   
			| "SQLSTATE"   
			| "SQLWARNING"   
			| "START"   
			| "STATIC"   
			| "SUBMULTISET"   
			| "SYMMETRIC"   
			| "SYSTEM"   
			| "SYSTEM_USER"   
			| "TABLE"   
			| "THEN"   
			| "TIME"   
			| "TIMESTAMP"   
			| "TIMEZONE_HOUR"   
			| "TIMEZONE_MINUTE"   
			| "TO"   
			| "TRAILING"   
			| "TRANSLATION"   
			| "TREAT"   
			| "TRIGGER"   
			| "TRUE"   
			| "UNION"   
			| "UNIQUE"   
			| "UNKNOWN"   
			| "UNNEST"   
			| "UPDATE"   
			| "USER"   
			| "USING"   
			| "VALUE"   
			| "VALUES"   
			| "VARCHAR"   
			| "VARYING"   
			| "WHEN"   
			| "WHENEVER"   
			| "WHERE"   
			| "WINDOW"   
			| "WITH"   
			| "WITHIN"   
			| "WITHOUT"   
			| "YEAR" ;;;
			Literal = SignedNumericLiteral  
			| GeneralLiteral;;;
			UnsignedLiteral = UnsignedNumericLiteral  
			| GeneralLiteral;;;
			GeneralLiteral = CharacterStringLiteral  
			| NationalCharacterStringLiteral  
			| UnicodeCharacterStringLiteral  
			| BinaryStringLiteral  
			| DatetimeLiteral  
			| IntervalLiteral  
			| BooleanLiteral;;;
			CharacterStringLiteral = !(Introducer >> CharacterSetSpecification >> ch_p('\'') >> *CharacterRepresentation >> ch_p('\'') >> *((Separator >> ch_p('\'') >> *CharacterRepresentation >> ch_p('\''))));;;
			Introducer = ch_p('_');;;
			CharacterRepresentation = NonquoteCharacter  
			| QuoteSymbol;;;
			NonquoteCharacter = nothing_p;;;
			QuoteSymbol = ch_p('\'') >> ch_p('\'');;;
			NationalCharacterStringLiteral = (N >> ch_p('\'') >> *CharacterRepresentation >> ch_p('\'') >> *((Separator >> ch_p('\'') >> *CharacterRepresentation >> ch_p('\''))));;;
			UnicodeCharacterStringLiteral = !(Introducer >> CharacterSetSpecification >> U  >> '&'  >> ch_p('\'') >> *UnicodeRepresentation >> ch_p('\'') >> *((Separator >> ch_p('\'') >> *UnicodeRepresentation >> ch_p('\''))) >> !(str_p("ESCAPE")) >> EscapeCharacter);;;
			UnicodeRepresentation = CharacterRepresentation  
			| UnicodeEscapeValue;;;
			BinaryStringLiteral = (X >> ch_p('\'') >> *(xdigit_p >> xdigit_p) >> ch_p('\'') >> *((Separator >> ch_p('\'') >> *(xdigit_p >> xdigit_p) >> ch_p('\''))) >> !(str_p("ESCAPE")) >> EscapeCharacter);;;
			SignedNumericLiteral = !(sign_p >> UnsignedNumericLiteral);;;
			UnsignedNumericLiteral = ExactNumericLiteral  
			| ApproximateNumericLiteral;;;
			ExactNumericLiteral = (uint_p >> !(ch_p('.') >> !uint_p))  
			| '.'  >> uint_p;;;
			sign_p = ch_p('+')  
			| '-' ;;;
			ApproximateNumericLiteral = Mantissa >> E >> Exponent;;;
			Mantissa = ExactNumericLiteral;;;
			Exponent = SignedInteger;;;
			SignedInteger = !(sign_p >> uint_p);;;
			DatetimeLiteral = DateLiteral  
			| TimeLiteral  
			| TimestampLiteral;;;
			DateLiteral =(str_p("DATE")) >> DateString;;;
			TimeLiteral =(str_p("TIME")) >> TimeString;;;
			TimestampLiteral =(str_p("TIMESTAMP")) >> TimestampString;;;
			DateString = ch_p('\'') >> UnquotedDateString >> ch_p('\'');;;
			TimeString = ch_p('\'') >> UnquotedTimeString >> ch_p('\'');;;
			TimestampString = ch_p('\'') >> UnquotedTimestampString >> ch_p('\'');;;
			TimeZoneInterval = sign_p >> HoursValue  >> ':'  >> MinutesValue;;;
			DateValue = YearsValue  >> '-'  >> MonthsValue  >> '-'  >> DaysValue;;;
			TimeValue = HoursValue  >> ':'  >> MinutesValue  >> ':'  >> SecondsValue;;;
			IntervalLiteral = ((str_p("INTERVAL")) >> !sign_p >> IntervalString >> IntervalQualifier);;;
			IntervalString = ch_p('\'') >> UnquotedIntervalString >> ch_p('\'');;;
			UnquotedDateString = DateValue;;;
			UnquotedTimeString = (TimeValue >> !TimeZoneInterval);;;
			UnquotedTimestampString = UnquotedDateString >> space_p >> UnquotedTimeString;;;
			UnquotedIntervalString = !(sign_p >> YearMonthLiteral  
									   | DayTimeLiteral);;;
			YearMonthLiteral = YearsValue  
			| !(YearsValue  >> '-'  >> MonthsValue);;;
			DayTimeLiteral = DayTimeInterval  
			| TimeInterval;;;
			DayTimeInterval = (DaysValue >> !(space_p >> HoursValue >> !(ch_p(':') >> MinutesValue >> !ch_p(':') >> SecondsValue)));;;
			TimeInterval = (HoursValue >> !(ch_p(':') >> MinutesValue >> !ch_p(':') >> SecondsValue))  
			| (MinutesValue >> !ch_p(':') >> SecondsValue)  
			| SecondsValue;;;
			YearsValue = DatetimeValue;;;
			MonthsValue = DatetimeValue;;;
			DaysValue = DatetimeValue;;;
			HoursValue = DatetimeValue;;;
			MinutesValue = DatetimeValue;;;
			SecondsValue = (SecondsIntegerValue >> !(ch_p('.') >> !SecondsFraction));;;
			SecondsIntegerValue = uint_p;;;
			SecondsFraction = uint_p;;;
			DatetimeValue = uint_p;;;
			BooleanLiteral =(str_p("TRUE"))  
			| "FALSE"   
			| "UNKNOWN" ;;;
			Identifier = ActualIdentifier;;;
			ActualIdentifier = RegularIdentifier  
			| DelimitedIdentifier;;;
			SQLLanguageIdentifier = (SQLLanguageIdentifierStart >> *(ch_p('_')  
																	 | SQLLanguageIdentifierPart));;;
			SQLLanguageIdentifierStart = alpha_p;;;
			SQLLanguageIdentifierPart = alpha_p  
			| digit_p;;;
			AuthorizationIdentifier = RoleName  
			| UserIdentifier;;;
			TableName = LocalOrSchemaQualifiedName;;;
			DomainName = SchemaQualifiedName;;;
			SchemaName = !(CatalogName  >> '.'  >> UnqualifiedSchemaName);;;
			CatalogName = Identifier;;;
			SchemaQualifiedName = !(SchemaName  >> '.'  >> QualifiedIdentifier);;;
			LocalOrSchemaQualifiedName = !(LocalOrSchemaQualifier  >> '.'  >> QualifiedIdentifier);;;
			LocalOrSchemaQualifier = SchemaName  
			| "MODULE" ;;;
			QualifiedIdentifier = Identifier;;;
			ColumnName = Identifier;;;
			CorrelationName = Identifier;;;
			QueryName = Identifier;;;
			SQLClientModuleName = Identifier;;;
			ProcedureName = Identifier;;;
			SchemaQualifiedRoutineName = SchemaQualifiedName;;;
			MethodName = Identifier;;;
			SpecificName = SchemaQualifiedName;;;
			CursorName = LocalQualifiedName;;;
			LocalQualifiedName = !(LocalQualifier  >> '.'  >> QualifiedIdentifier);;;
			LocalQualifier =(str_p("MODULE"));;;
			HostParameterName = ch_p(':') >> Identifier;;;
			SQLParameterName = Identifier;;;
			ConstraintName = SchemaQualifiedName;;;
			ExternalRoutineName = Identifier  
			| CharacterStringLiteral;;;
			TriggerName = SchemaQualifiedName;;;
			CollationName = SchemaQualifiedName;;;
			CharacterSetName = !(SchemaName  >> '.'  >> SQLLanguageIdentifier);;;
			TransliterationName = SchemaQualifiedName;;;
			TranscodingName = SchemaQualifiedName;;;
			UserDefinedTypeName = SchemaQualifiedTypeName;;;
			SchemaResolvedUserDefinedTypeName = UserDefinedTypeName;;;
			SchemaQualifiedTypeName = !(SchemaName  >> '.'  >> QualifiedIdentifier);;;
			AttributeName = Identifier;;;
			FieldName = Identifier;;;
			SavepointName = Identifier;;;
			SequenceGeneratorName = SchemaQualifiedName;;;
			RoleName = Identifier;;;
			UserIdentifier = Identifier;;;
			ConnectionName = SimpleValueSpecification;;;
			SQLServerName = SimpleValueSpecification;;;
			ConnectionUserName = SimpleValueSpecification;;;
			SQLStatementName = StatementName  
			| ExtendedStatementName;;;
			StatementName = Identifier;;;
			ExtendedStatementName = !(ScopeOption >> SimpleValueSpecification);;;
			DynamicCursorName = CursorName  
			| ExtendedCursorName;;;
			ExtendedCursorName = !(ScopeOption >> SimpleValueSpecification);;;
			DescriptorName = !(ScopeOption >> SimpleValueSpecification);;;
			ScopeOption =(str_p("GLOBAL"))  
			| "LOCAL" ;;;
			WindowName = Identifier;;;
			DataType = PredefinedType  
			| RowType  
			| PathResolvedUserDefinedTypeName  
			| ReferenceType  
			| CollectionType;;;
			PredefinedType = (CharacterStringType >> !(str_p("CHARACTER"))  >> "SET"  >> CharacterSetSpecification >> !CollateClause)  
			| (NationalCharacterStringType >> !CollateClause)  
			| BinaryLargeObjectStringType  
			| NumericType  
			| BooleanType  
			| DatetimeType  
			| IntervalType;;;
			CharacterStringType = ((str_p("CHARACTER")) >> !ch_p('(') >> Length  >> ')' )  
			| ((str_p("CHAR")) >> !ch_p('(') >> Length  >> ')' )  
			| "CHARACTER"   >> "VARYING"   >> '('  >> Length  >> ')'   
			| "CHAR"   >> "VARYING"   >> '('  >> Length  >> ')'   
			| "VARCHAR"   >> '('  >> Length  >> ')'   
			| ((str_p("CHARACTER"))  >> "LARGE"   >> "OBJECT"  >> !ch_p('(') >> LargeObjectLength  >> ')' )  
			| ((str_p("CHAR"))  >> "LARGE"   >> "OBJECT"  >> !ch_p('(') >> LargeObjectLength  >> ')' )  
			| ((str_p("CLOB")) >> !ch_p('(') >> LargeObjectLength  >> ')' );;;
			NationalCharacterStringType = ((str_p("NATIONAL"))  >> "CHARACTER"  >> !ch_p('(') >> Length  >> ')' )  
			| ((str_p("NATIONAL"))  >> "CHAR"  >> !ch_p('(') >> Length  >> ')' )  
			| ((str_p("NCHAR")) >> !ch_p('(') >> Length  >> ')' )  
			| "NATIONAL"   >> "CHARACTER"   >> "VARYING"   >> '('  >> Length  >> ')'   
			| "NATIONAL"   >> "CHAR"   >> "VARYING"   >> '('  >> Length  >> ')'   
			| "NCHAR"   >> "VARYING"   >> '('  >> Length  >> ')'   
			| ((str_p("NATIONAL"))  >> "CHARACTER"   >> "LARGE"   >> "OBJECT"  >> !ch_p('(') >> LargeObjectLength  >> ')' )  
			| ((str_p("NCHAR"))  >> "LARGE"   >> "OBJECT"  >> !ch_p('(') >> LargeObjectLength  >> ')' )  
			| ((str_p("NCLOB")) >> !ch_p('(') >> LargeObjectLength  >> ')' );;;
			BinaryLargeObjectStringType = ((str_p("BINARY"))  >> "LARGE"   >> "OBJECT"  >> !ch_p('(') >> LargeObjectLength  >> ')' )  
			| ((str_p("BLOB")) >> !ch_p('(') >> LargeObjectLength  >> ')' );;;
			NumericType = ExactNumericType  
			| ApproximateNumericType;;;
			ExactNumericType = ((str_p("NUMERIC")) >> !(ch_p('(') >> Precision >> !ch_p(',') >> Scale  >> ')' ))  
			| ((str_p("DECIMAL")) >> !(ch_p('(') >> Precision >> !ch_p(',') >> Scale  >> ')' ))  
			| ((str_p("DEC")) >> !(ch_p('(') >> Precision >> !ch_p(',') >> Scale  >> ')' ))  
			| "SMALLINT"   
			| "INTEGER"   
			| "INT"   
			| "BIGINT" ;;;
			ApproximateNumericType = ((str_p("FLOAT")) >> !ch_p('(') >> Precision  >> ')' )  
			| "REAL"   
			| "DOUBLE"   >> "PRECISION" ;;;
			Length = uint_p;;;
			LargeObjectLength = (uint_p >> !Multiplier >> !CharLengthUnits)  
			| (LargeObjectLengthToken >> !CharLengthUnits);;;
			CharLengthUnits =(str_p("CHARACTERS"))  
			| "CODE_UNITS"   
			| "OCTETS" ;;;
			Precision = uint_p;;;
			Scale = uint_p;;;
			BooleanType =(str_p("BOOLEAN"));;;
			DatetimeType =(str_p("DATE"))  
			| ((str_p("TIME")) >> !ch_p('(') >> TimePrecision  >> ')'  >> !WithOrWithoutTimeZone)  
			| ((str_p("TIMESTAMP")) >> !ch_p('(') >> TimestampPrecision  >> ')'  >> !WithOrWithoutTimeZone);;;
			WithOrWithoutTimeZone =(str_p("WITH"))  >> "TIME"   >> "ZONE"   
			| "WITHOUT"   >> "TIME"   >> "ZONE" ;;;
			TimePrecision = TimeFractionalSecondsPrecision;;;
			TimestampPrecision = TimeFractionalSecondsPrecision;;;
			TimeFractionalSecondsPrecision = uint_p;;;
			IntervalType =(str_p("INTERVAL")) >> IntervalQualifier;;;
			RowType =(str_p("ROW")) >> RowTypeBody;;;
			RowTypeBody = (ch_p('(') >> (FieldDefinition%ch_p(','))  >> ')' );;;
			ReferenceType = ((str_p("REF"))  >> '('  >> ReferencedType  >> ')'  >> !ScopeClause);;;
			ScopeClause = "SCOPE" >> TableName;;;
			ReferencedType = PathResolvedUserDefinedTypeName;;;
			PathResolvedUserDefinedTypeName = UserDefinedTypeName;;;
			PathResolvedUserDefinedTypeName = UserDefinedTypeName;;;
			CollectionType = ArrayType  
			| MultisetType;;;
			ArrayType = (DataType  >> "ARRAY"  >> !LeftBracketOrTrigraph >> uint_p
						 >> RightBracketOrTrigraph);;;
			MultisetType = DataType  >> "MULTISET" ;;;
			FieldDefinition = (FieldName >> DataType >> !ReferenceScopeCheck);;;
			ValueExpressionPrimary = ParenthesizedValueExpression  
			| NonparenthesizedValueExpressionPrimary;;;
			ParenthesizedValueExpression = ch_p('(') >> ValueExpression  >> ')' ;;;
			NonparenthesizedValueExpressionPrimary = UnsignedValueSpecification  
			| ColumnReference  
			| SetFunctionSpecification  
			| WindowFunction  
			| ScalarSubquery  
			| CaseExpression  
			| CastSpecification  
			| FieldReference  
			| SubtypeTreatment  
			| MethodInvocation  
			| StaticMethodInvocation  
			| NewSpecification  
			| AttributeOrMethodReference  
			| ReferenceResolution  
			| CollectionValueConstructor  
			| ArrayElementReference  
			| MultisetElementReference  
			| RoutineInvocation  
			| NextValueExpression;;;
			ValueSpecification = Literal  
			| GeneralValueSpecification;;;
			UnsignedValueSpecification = UnsignedLiteral  
			| GeneralValueSpecification;;;
			GeneralValueSpecification = HostParameterSpecification  
			| SQLParameterReference  
			| DynamicParameterSpecification  
			| EmbeddedVariableSpecification  
			| CurrentCollationSpecification  
			| "CURRENT_DEFAULT_TRANSFORM_GROUP"   
			| "CURRENT_PATH"   
			| "CURRENT_ROLE"   
			| "CURRENT_TRANSFORM_GROUP_FOR_TYPE"  >> PathResolvedUserDefinedTypeName  
			| "CURRENT_USER"   
			| "SESSION_USER"   
			| "SYSTEM_USER"   
			| "USER"   
			| "VALUE" ;;;
			SimpleValueSpecification = Literal  
			| HostParameterName  
			| SQLParameterReference  
			| EmbeddedVariableName;;;
			TargetSpecification = HostParameterSpecification  
			| SQLParameterReference  
			| ColumnReference  
			| TargetArrayElementSpecification  
			| DynamicParameterSpecification  
			| EmbeddedVariableSpecification;;;
			SimpleTargetSpecification = HostParameterSpecification  
			| SQLParameterReference  
			| ColumnReference  
			| EmbeddedVariableName;;;
			HostParameterSpecification = (HostParameterName >> !IndicatorParameter);;;
			DynamicParameterSpecification = ch_p('?');;;
			EmbeddedVariableSpecification = (EmbeddedVariableName >> !IndicatorVariable);;;
			IndicatorVariable = !((str_p("INDICATOR")) >> EmbeddedVariableName);;;
			IndicatorParameter = !((str_p("INDICATOR")) >> HostParameterName);;;
			TargetArrayElementSpecification = TargetArrayReference >> LeftBracketOrTrigraph >> SimpleValueSpecification >> RightBracketOrTrigraph;;;
			TargetArrayReference = SQLParameterReference  
			| ColumnReference;;;
			CurrentCollationSpecification =(str_p("CURRENT_COLLATION"))  >> '('  >> StringValueExpression  >> ')' ;;;
			ContextuallyTypedValueSpecification = ImplicitlyTypedValueSpecification  
			| DefaultSpecification;;;
			ImplicitlyTypedValueSpecification = NullSpecification  
			| EmptySpecification;;;
			NullSpecification =(str_p("NULL"));;;
			EmptySpecification =(str_p("ARRAY")) >> LeftBracketOrTrigraph >> RightBracketOrTrigraph  
			| "MULTISET"  >> LeftBracketOrTrigraph >> RightBracketOrTrigraph;;;
			DefaultSpecification =(str_p("DEFAULT"));;;
			IdentifierChain = ((Identifier%ch_p('.')));;;
			BasicIdentifierChain = IdentifierChain;;;
			ColumnReference = BasicIdentifierChain  
			| "MODULE"   >> '.'  >> QualifiedIdentifier  >> '.'  >> ColumnName;;;
			SQLParameterReference = BasicIdentifierChain;;;
			SetFunctionSpecification = AggregateFunction  
			| GroupingOperation;;;
			GroupingOperation = ((str_p("GROUPING"))  >> '('  >> (ColumnReference%ch_p(','))  >> ')' );;;
			WindowFunction = WindowFunctionType  >> "OVER"  >> WindowNameOrSpecification;;;
			WindowFunctionType = RankFunctionType  >> '('   >> ')'   
			| "ROW_NUMBER"   >> '('   >> ')'   
			| AggregateFunction;;;
			RankFunctionType =(str_p("RANK"))  
			| "DENSE_RANK"   
			| "PERCENT_RANK"   
			| "CUME_DIST" ;;;
			WindowNameOrSpecification = WindowName  
			| InLineWindowSpecification;;;
			InLineWindowSpecification = WindowSpecification;;;
			CaseExpression = CaseAbbreviation  
			| CaseSpecification;;;
			CaseAbbreviation =(str_p("NULLIF"))  >> '('  >> ValueExpression  >> ','  >> ValueExpression  >> ')'   
			| ((str_p("COALESCE"))  >> '('  >> ValueExpression >> +ch_p(',') >> ValueExpression  >> ')' );;;
			CaseSpecification = SimpleCase  
			| SearchedCase;;;
			SimpleCase = ((str_p("CASE")) >> CaseOperand >> +SimpleWhenClause >> !ElseClause  >> "END" );;;
			SearchedCase = ((str_p("CASE")) >> +SearchedWhenClause >> !ElseClause  >> "END" );;;
			SimpleWhenClause =(str_p("WHEN")) >> WhenOperand  >> "THEN"  >> Result;;;
			SearchedWhenClause =(str_p("WHEN")) >> SearchCondition  >> "THEN"  >> Result;;;
			ElseClause =(str_p("ELSE")) >> Result;;;
			CaseOperand = RowValuePredicand  
			| OverlapsPredicatePart;;;
			WhenOperand = RowValuePredicand  
			| ComparisonPredicatePart2  
			| BetweenPredicatePart2  
			| InPredicatePart2  
			| CharacterLikePredicatePart2  
			| OctetLikePredicatePart2  
			| SimilarPredicatePart2  
			| NullPredicatePart2  
			| QuantifiedComparisonPredicatePart2  
			| MatchPredicatePart2  
			| OverlapsPredicatePart2  
			| DistinctPredicatePart2  
			| MemberPredicatePart2  
			| SubmultisetPredicatePart2  
			| SetPredicatePart2  
			| TypePredicatePart2;;;
			Result = ResultExpression  
			| "NULL" ;;;
			ResultExpression = ValueExpression;;;
			CastSpecification =(str_p("CAST"))  >> '('  >> CastOperand  >> "AS"  >> CastTarget  >> ')' ;;;
			CastOperand = ValueExpression  
			| ImplicitlyTypedValueSpecification;;;
			CastTarget = DomainName  
			| DataType;;;
			NextValueExpression =(str_p("NEXT"))  >> "VALUE"   >> "FOR"  >> SequenceGeneratorName;;;
			FieldReference = ValueExpressionPrimary  >> '.'  >> FieldName;;;
			SubtypeTreatment =(str_p("TREAT"))  >> '('  >> SubtypeOperand  >> "AS"  >> TargetSubtype  >> ')' ;;;
			SubtypeOperand = ValueExpression;;;
			TargetSubtype = PathResolvedUserDefinedTypeName  
			| ReferenceType;;;
			MethodInvocation = DirectInvocation  
			| GeneralizedInvocation;;;
			DirectInvocation = (ValueExpressionPrimary  >> '.'  >> MethodName >> !SQLArgumentList);;;
			GeneralizedInvocation = (ch_p('(') >> ValueExpressionPrimary  >> "AS"  >> DataType  >> ')'   >> '.'  >> MethodName >> !SQLArgumentList);;;
			MethodSelection = RoutineInvocation;;;
			ConstructorMethodSelection = RoutineInvocation;;;
			StaticMethodInvocation = (PathResolvedUserDefinedTypeName >> DoubleColon >> MethodName >> !SQLArgumentList);;;
			StaticMethodSelection = RoutineInvocation;;;
			NewSpecification =(str_p("NEW")) >> RoutineInvocation;;;
			NewInvocation = MethodInvocation  
			| RoutineInvocation;;;
			AttributeOrMethodReference = (ValueExpressionPrimary >> DereferenceOperator >> QualifiedIdentifier >> !SQLArgumentList);;;
			DereferenceOperator = RightArrow;;;
			DereferenceOperation = ReferenceValueExpression >> DereferenceOperator >> AttributeName;;;
			MethodReference = ValueExpressionPrimary >> DereferenceOperator >> MethodName >> SQLArgumentList;;;
			ReferenceResolution =(str_p("DEREF"))  >> '('  >> ReferenceValueExpression  >> ')' ;;;
			ArrayElementReference = ArrayValueExpression >> LeftBracketOrTrigraph >> NumericValueExpression >> RightBracketOrTrigraph;;;
			MultisetElementReference =(str_p("ELEMENT"))  >> '('  >> MultsetValueExpression  >> ')' ;;;
			ValueExpression = CommonValueExpression  
			| BooleanValueExpression  
			| RowValueExpression;;;
			CommonValueExpression = NumericValueExpression  
			| StringValueExpression  
			| DatetimeValueExpression  
			| IntervalValueExpression  
			| UserDefinedTypeValueExpression  
			| ReferenceValueExpression  
			| CollectionValueExpression;;;
			UserDefinedTypeValueExpression = ValueExpressionPrimary;;;
			ReferenceValueExpression = ValueExpressionPrimary;;;
			CollectionValueExpression = ArrayValueExpression  
			| MultisetValueExpression;;;
			CollectionValueConstructor = ArrayValueConstructor  
			| MultisetValueConstructor;;;
			NumericValueExpression = !sign_p >>  Term ;;;
			Term = Factor  
			| Term  >> '*'  >> Factor  
			| Term  >> '/'  >> Factor;;;
			Factor = !(sign_p
					   >> NumericPrimary);;;
			NumericPrimary = ValueExpressionPrimary  
			| NumericValueFunction;;;
			NumericValueFunction = PositionExpression  
			| ExtractExpression  
			| LengthExpression  
			| CardinalityExpression  
			| AbsoluteValueExpression  
			| ModulusExpression  
			| NaturalLogarithm  
			| ExponentialFunction  
			| PowerFunction  
			| SquareRoot  
			| FloorFunction  
			| CeilingFunction  
			| WidthBucketFunction;;;
			PositionExpression = StringPositionExpression  
			| BlobPositionExpression;;;
			StringPositionExpression = ((str_p("POSITION"))  >> '('  >> StringValueExpression  >> "IN"  >> StringValueExpression >> !(str_p("USING")) >> CharLengthUnits  >> ')' );;;
			BlobPositionExpression =(str_p("POSITION"))  >> '('  >> BlobValueExpression  >> "IN"  >> BlobValueExpression  >> ')' ;;;
			LengthExpression = CharLengthExpression  
			| OctetLengthExpression;;;
			CharLengthExpression = ((str_p("CHAR_LENGTH"))  
									| "CHARACTER_LENGTH"   >> '('  >> StringValueExpression >> !(str_p("USING")) >> CharLengthUnits  >> ')' );;;
			OctetLengthExpression =(str_p("OCTET_LENGTH"))  >> '('  >> StringValueExpression  >> ')' ;;;
			ExtractExpression =(str_p("EXTRACT"))  >> '('  >> ExtractField  >> "FROM"  >> ExtractSource  >> ')' ;;;
			ExtractField = PrimaryDatetimeField  
			| TimeZoneField;;;
			TimeZoneField =(str_p("TIMEZONE_HOUR"))  
			| "TIMEZONE_MINUTE" ;;;
			ExtractSource = DatetimeValueExpression  
			| IntervalValueExpression;;;
			CardinalityExpression =(str_p("CARDINALITY"))  >> '('  >> CollectionValueExpression  >> ')' ;;;
			AbsoluteValueExpression =(str_p("ABS"))  >> '('  >> NumericValueExpression  >> ')' ;;;
			ModulusExpression =(str_p("MOD"))  >> '('  >> NumericValueExpressionDividend  >> ','  >> NumericValueExpressionDivisor  >> ')' ;;;
			NaturalLogarithm =(str_p("LN"))  >> '('  >> NumericValueExpression  >> ')' ;;;
			ExponentialFunction =(str_p("EXP"))  >> '('  >> NumericValueExpression  >> ')' ;;;
			PowerFunction =(str_p("POWER"))  >> '('  >> NumericValueExpressionBase  >> ','  >> NumericValueExpressionExponent  >> ')' ;;;
			NumericValueExpressionBase = NumericValueExpression;;;
			NumericValueExpressionExponent = NumericValueExpression;;;
			SquareRoot =(str_p("SQRT"))  >> '('  >> NumericValueExpression  >> ')' ;;;
			FloorFunction =(str_p("FLOOR"))  >> '('  >> NumericValueExpression  >> ')' ;;;
			CeilingFunction = ((str_p("CEIL"))  
							   | "CEILING"   >> '('  >> NumericValueExpression  >> ')' );;;
			WidthBucketFunction =(str_p("WIDTH_BUCKET"))  >> '('  >> WidthBucketOperand  >> ','  >> WidthBucketBound1  >> ','  >> WidthBucketBound2  >> ','  >> WidthBucketCount  >> ')' ;;;
			WidthBucketOperand = NumericValueExpression;;;
			WidthBucketBound1 = NumericValueExpression;;;
			WidthBucketBound2 = NumericValueExpression;;;
			WidthBucketCount = NumericValueExpression;;;
			StringValueExpression = CharacterValueExpression  
			| BlobValueExpression;;;
			CharacterValueExpression = Concatenation  
			| CharacterFactor;;;
			Concatenation = CharacterValueExpression >> ConcatenationOperator >> CharacterFactor;;;
			CharacterFactor = (CharacterPrimary >> !CollateClause);;;
			CharacterPrimary = ValueExpressionPrimary  
			| StringValueFunction;;;
			BlobValueExpression = BlobConcatenation  
			| BlobFactor;;;
			BlobFactor = BlobPrimary;;;
			BlobPrimary = ValueExpressionPrimary  
			| StringValueFunction;;;
			BlobConcatenation = BlobValueExpression >> ConcatenationOperator >> BlobFactor;;;
			StringValueFunction = CharacterValueFunction  
			| BlobValueFunction;;;
			CharacterValueFunction = CharacterSubstringFunction  
			| RegularExpressionSubstringFunction  
			| Fold  
			| Transcoding  
			| CharacterTransliteration  
			| TrimFunction  
			| CharacterOverlayFunction  
			| NormalizeFunction  
			| SpecificTypeMethod;;;
			CharacterSubstringFunction = ((str_p("SUBSTRING"))  >> '('  >> CharacterValueExpression  >> "FROM"  >> StartPosition >> !(str_p("FOR")) >> StringLength >> !(str_p("USING")) >> CharLengthUnits  >> ')' );;;
			RegularExpressionSubstringFunction =(str_p("SUBSTRING"))  >> '('  >> CharacterValueExpression  >> "SIMILAR"  >> CharacterValueExpression  >> "ESCAPE"  >> EscapeCharacter  >> ')' ;;;
			Fold = ((str_p("UPPER"))  
					| "LOWER"   >> '('  >> CharacterValueExpression  >> ')' );;;
			Transcoding =(str_p("CONVERT"))  >> '('  >> CharacterValueExpression  >> "USING"  >> TranscodingName  >> ')' ;;;
			CharacterTransliteration =(str_p("TRANSLATE"))  >> '('  >> CharacterValueExpression  >> "USING"  >> TransliterationName  >> ')' ;;;
			TrimFunction =(str_p("TRIM"))  >> '('  >> TrimOperands  >> ')' ;;;
			TrimOperands = !(!(TrimSpecification >> !TrimCharacter  >> "FROM" ) >> TrimSource);;;
			TrimSource = CharacterValueExpression;;;
			TrimSpecification =(str_p("LEADING"))  
			| "TRAILING"   
			| "BOTH" ;;;
			TrimCharacter = CharacterValueExpression;;;
			CharacterOverlayFunction = ((str_p("OVERLAY"))  >> '('  >> CharacterValueExpression  >> "PLACING"  >> CharacterValueExpression  >> "FROM"  >> StartPosition >> !(str_p("FOR")) >> StringLength >> !(str_p("USING")) >> CharLengthUnits  >> ')' );;;
			NormalizeFunction =(str_p("NORMALIZE"))  >> '('  >> CharacterValueExpression  >> ')' ;;;
			SpecificTypeMethod = UserDefinedTypeValueExpression  >> '.'   >> "SPECIFICTYPE" ;;;
			BlobValueFunction = BlobSubstringFunction  
			| BlobTrimFunction  
			| BlobOverlayFunction;;;
			BlobSubstringFunction = ((str_p("SUBSTRING"))  >> '('  >> BlobValueExpression  >> "FROM"  >> StartPosition >> !(str_p("FOR")) >> StringLength  >> ')' );;;
			BlobTrimFunction =(str_p("TRIM"))  >> '('  >> BlobTrimOperands  >> ')' ;;;
			BlobTrimOperands = !(!(TrimSpecification >> !TrimOctet  >> "FROM" ) >> BlobTrimSource);;;
			BlobTrimSource = BlobValueExpression;;;
			TrimOctet = BlobValueExpression;;;
			BlobOverlayFunction = ((str_p("OVERLAY"))  >> '('  >> BlobValueExpression  >> "PLACING"  >> BlobValueExpression  >> "FROM"  >> StartPosition >> !(str_p("FOR")) >> StringLength  >> ')' );;;
			StartPosition = NumericValueExpression;;;
			StringLength = NumericValueExpression;;;
			DatetimeValueExpression = DatetimeTerm  
			| IntervalValueExpression  >> '+'  >> DatetimeTerm  
			| DatetimeValueExpression  >> '+'  >> IntervalTerm  
			| DatetimeValueExpression  >> '-'  >> IntervalTerm;;;
			DatetimeTerm = DatetimeFactor;;;
			DatetimeFactor = (DatetimePrimary >> !TimeZone);;;
			DatetimePrimary = ValueExpressionPrimary  
			| DatetimeValueFunction;;;
			TimeZone =(str_p("AT")) >> TimeZoneSpecifier;;;
			TimeZoneSpecifier =(str_p("LOCAL"))  
			| "TIME"   >> "ZONE"  >> IntervalPrimary;;;
			DatetimeValueFunction = CurrentDateValueFunction  
			| CurrentTimeValueFunction  
			| CurrentTimestampValueFunction  
			| CurrentLocalTimeValueFunction  
			| CurrentLocalTimestampValueFunction;;;
			CurrentDateValueFunction =(str_p("CURRENT_DATE"));;;
			CurrentTimeValueFunction = ((str_p("CURRENT_TIME")) >> !ch_p('(') >> TimePrecision  >> ')' );;;
			CurrentLocalTimeValueFunction = ((str_p("LOCALTIME")) >> !ch_p('(') >> TimePrecision  >> ')' );;;
			CurrentTimestampValueFunction = ((str_p("CURRENT_TIMESTAMP")) >> !ch_p('(') >> TimestampPrecision  >> ')' );;;
			CurrentLocalTimestampValueFunction = ((str_p("LOCALTIMESTAMP")) >> !ch_p('(') >> TimestampPrecision  >> ')' );;;
			IntervalValueExpression = IntervalTerm  
			| IntervalValueExpression1  >> '+'  >> IntervalTerm1  
			| IntervalValueExpression1  >> '-'  >> IntervalTerm1  
			| '('  >> DatetimeValueExpression  >> '-'  >> DatetimeTerm  >> ')'  >> IntervalQualifier;;;
			IntervalTerm = IntervalFactor  
			| IntervalTerm2  >> '*'  >> Factor  
			| IntervalTerm2  >> '/'  >> Factor  
			| Term  >> '*'  >> IntervalFactor;;;
			IntervalFactor = !(sign_p >> IntervalPrimary);;;
			IntervalPrimary = (ValueExpressionPrimary >> !IntervalQualifier)  
			| IntervalValueFunction;;;
			IntervalValueExpression1 = IntervalValueExpression;;;
			IntervalTerm1 = IntervalTerm;;;
			IntervalTerm2 = IntervalTerm;;;
			IntervalValueFunction = IntervalAbsoluteValueFunction;;;
			IntervalAbsoluteValueFunction =(str_p("ABS"))  >> '('  >> IntervalValueExpression  >> ')' ;;;
			BooleanValueExpression = BooleanTerm  
			| BooleanValueExpression  >> "OR"  >> BooleanTerm;;;
			BooleanTerm = BooleanFactor  
			| BooleanTerm  >> "AND"  >> BooleanFactor;;;
			BooleanFactor = !((str_p("NOT")) >> BooleanTest);;;
			BooleanTest = (BooleanPrimary >> !((str_p("IS")) >> !(str_p("NOT")) >> TruthValue));;;
			TruthValue =(str_p("TRUE"))  
			| "FALSE"   
			| "UNKNOWN" ;;;
			BooleanPrimary = Predicate  
			| BooleanPredicand;;;
			BooleanPredicand = ParenthesizedBooleanValueExpression  
			| NonparenthesizedValueExpressionPrimary;;;
			ParenthesizedBooleanValueExpression = ch_p('(') >> BooleanValueExpression  >> ')' ;;;
			ArrayValueExpression = ArrayConcatenation  
			| ArrayFactor;;;
			ArrayConcatenation = ArrayValueExpression1 >> ConcatenationOperator >> ArrayFactor;;;
			ArrayValueExpression1 = ArrayValueExpression;;;
			ArrayFactor = ValueExpressionPrimary;;;
			ArrayValueConstructor = ArrayValueConstructorByEnumeration  
			| ArrayValueConstructorByQuery;;;
			ArrayValueConstructorByEnumeration =(str_p("ARRAY")) >> LeftBracketOrTrigraph >> ArrayElementList >> RightBracketOrTrigraph;;;
			ArrayElementList = ((ArrayElement%ch_p(',')));;;
			ArrayElement = ValueExpression;;;
			ArrayValueConstructorByQuery = ((str_p("ARRAY"))  >> '('  >> QueryExpression >> !OrderByClause  >> ')' );;;
			MultisetValueExpression = MultisetTerm  
			| (MultisetValueExpression  >> "MULTISET"   >> "UNION"  >> !(str_p("ALL"))  
			   | "DISTINCT"  >> MultisetTerm)  
			| (MultisetValueExpression  >> "MULTISET"   >> "EXCEPT"  >> !(str_p("ALL"))  
			   | "DISTINCT"  >> MultisetTerm);;;
			MultisetTerm = MultisetPrimary  
			| (MultisetTerm  >> "MULTISET"   >> "INTERSECT"  >> !(str_p("ALL"))  
			   | "DISTINCT"  >> MultisetPrimary);;;
			MultisetPrimary = MultisetValueFunction  
			| ValueExpressionPrimary;;;
			MultisetValueFunction = MultisetSetFunction;;;
			MultisetSetFunction =(str_p("SET"))  >> '('  >> MultisetValueExpression  >> ')' ;;;
			MultisetValueConstructor = MultisetValueConstructorByEnumeration  
			| MultisetValueConstructorByQuery  
			| TableValueConstructorByQuery;;;
			MultisetValueConstructorByEnumeration =(str_p("MULTISET")) >> LeftBracketOrTrigraph >> MultisetElementList >> RightBracketOrTrigraph;;;
			MultisetElementList = (MultisetElement >> !(ch_p(',') >> MultisetElement));;;
			MultisetElement = ValueExpression;;;
			MultisetValueConstructorByQuery =(str_p("MULTISET"))  >> '('  >> QueryExpression  >> ')' ;;;
			TableValueConstructorByQuery =(str_p("TABLE"))  >> '('  >> QueryExpression  >> ')'  >> Specify >> A >> Value >> Or >> List >> Of >> Values >> To >> Be >> Constructed >> Into >> A >> Row >> Or >> Partial >> Row.;;;
			RowValueConstructor = CommonValueExpression  
			| BooleanValueExpression  
			| ExplicitRowValueConstructor;;;
			ExplicitRowValueConstructor = ch_p('(') >> RowValueConstructorElement  >> ','  >> RowValueConstructorElementList  >> ')'   
			| "ROW"   >> '('  >> RowValueConstructorElementList  >> ')'   
			| RowSubquery;;;
			RowValueConstructorElementList = ((RowValueConstructorElement%ch_p(',')));;;
			RowValueConstructorElement = ValueExpression;;;
			ContextuallyTypedRowValueConstructor = CommonValueExpression  
			| BooleanValueExpression  
			| ContextuallyTypedValueSpecification  
			| '('  >> ContextuallyTypedRowValueConstructorElement  >> ','  >> ContextuallyTypedRowValueConstructorElementList  >> ')'   
			| "ROW"   >> '('  >> ContextuallyTypedRowValueConstructorElementList  >> ')' ;;;
			ContextuallyTypedRowValueConstructorElementList = ((ContextuallyTypedRowValueConstructorElement%ch_p(',')));;;
			ContextuallyTypedRowValueConstructorElement = ValueExpression  
			| ContextuallyTypedValueSpecification;;;
			RowValueConstructorPredicand = CommonValueExpression  
			| BooleanPredicand  
			| ExplicitRowValueConstructor;;;
			RowValueExpression = RowValueSpecialCase  
			| ExplicitRowValueConstructor;;;
			TableRowValueExpression = RowValueSpecialCase  
			| RowValueConstructor;;;
			ContextuallyTypedRowValueExpression = RowValueSpecialCase  
			| ContextuallyTypedRowValueConstructor;;;
			RowValuePredicand = RowValueSpecialCase  
			| RowValueConstructorPredicand;;;
			RowValueSpecialCase = NonparenthesizedValueExpressionPrimary;;;
			TableValueConstructor =(str_p("VALUES")) >> RowValueExpressionList;;;
			RowValueExpressionList = ((TableRowValueExpression%ch_p(',')));;;
			ContextuallyTypedTableValueConstructor =(str_p("VALUES")) >> ContextuallyTypedRowValueExpressionList;;;
			ContextuallyTypedRowValueExpressionList = ((ContextuallyTypedRowValueExpression%ch_p(',')));;;
			TableExpression = (FromClause >> !WhereClause >> !GroupByClause >> !HavingClause >> !WindowClause);;;
			FromClause =(str_p("FROM")) >> TableReferenceList;;;
			TableReferenceList = ((TableReference%ch_p(',')));;;
			TableReference = (TablePrimaryOrJoinedTable >> !SampleClause);;;
			TablePrimaryOrJoinedTable = TablePrimary  
			| JoinedTable;;;
			SampleClause = ((str_p("TABLESAMPLE")) >> SampleMethod  >> '('  >> SamplePercentage  >> ')'  >> !RepeatableClause);;;
			SampleMethod =(str_p("BERNOULLI"))  
			| "SYSTEM" ;;;
			RepeatableClause =(str_p("REPEATABLE"))  >> '('  >> RepeatArgument  >> ')' ;;;
			SamplePercentage = NumericValueExpression;;;
			RepeatArgument = NumericValueExpression;;;
			TablePrimary = (TableOrQueryName >> !!((str_p("AS")) >> CorrelationName >> !ch_p('(') >> DerivedColumnList  >> ')' ))  
			| (DerivedTable >> !(str_p("AS")) >> CorrelationName >> !ch_p('(') >> DerivedColumnList  >> ')' )  
			| (LateralDerivedTable >> !(str_p("AS")) >> CorrelationName >> !ch_p('(') >> DerivedColumnList  >> ')' )  
			| (CollectionDerivedTable >> !(str_p("AS")) >> CorrelationName >> !ch_p('(') >> DerivedColumnList  >> ')' )  
			| (TableFunctionDerivedTable >> !(str_p("AS")) >> CorrelationName >> !ch_p('(') >> DerivedColumnList  >> ')' )  
			| (OnlySpec >> !!((str_p("AS")) >> CorrelationName >> !ch_p('(') >> DerivedColumnList  >> ')' ))  
			| '('  >> JoinedTable  >> ')' ;;;
			OnlySpec =(str_p("ONLY"))  >> '('  >> TableOrQueryName  >> ')' ;;;
			LateralDerivedTable =(str_p("LATERAL")) >> TableSubquery;;;
			CollectionDerivedTable = ((str_p("UNNEST"))  >> '('  >> CollectionValueExpression  >> ')'  >> !(str_p("WITH"))  >> "ORDINALITY" );;;
			TableFunctionDerivedTable =(str_p("TABLE"))  >> '('  >> CollectionValueExpression  >> ')' ;;;
			DerivedTable = TableSubquery;;;
			TableOrQueryName = TableName  
			| QueryName;;;
			DerivedColumnList = ColumnNameList;;;
			ColumnNameList = ((ColumnName%ch_p(',')));;;
			JoinedTable = CrossJoin  
			| QualifiedJoin  
			| NaturalJoin  
			| UnionJoin;;;
			CrossJoin = TableReference  >> "CROSS"   >> "JOIN"  >> TablePrimary;;;
			QualifiedJoin = (TableReference >> !JoinType  >> "JOIN"  >> TableReference >> JoinSpecification);;;
			NaturalJoin = (TableReference  >> "NATURAL"  >> !JoinType  >> "JOIN"  >> TablePrimary);;;
			UnionJoin = TableReference  >> "UNION"   >> "JOIN"  >> TablePrimary;;;
			JoinSpecification = JoinCondition  
			| NamedColumnsJoin;;;
			JoinCondition =(str_p("ON")) >> SearchCondition;;;
			NamedColumnsJoin =(str_p("USING"))  >> '('  >> JoinColumnList  >> ')' ;;;
			JoinType =(str_p("INNER"))  
			| (OuterJoinType >> !(str_p("OUTER")));;;
			OuterJoinType =(str_p("LEFT"))  
			| "RIGHT"   
			| "FULL" ;;;
			JoinColumnList = ColumnNameList;;;
			WhereClause =(str_p("WHERE")) >> SearchCondition;;;
			GroupByClause = ((str_p("GROUP"))  >> "BY"  >> !SetQuantifier >> GroupingElementList);;;
			GroupingElementList = ((GroupingElement%ch_p(',')));;;
			GroupingElement = OrdinaryGroupingSet  
			| RollupList  
			| CubeList  
			| GroupingSetsSpecification  
			| EmptyGroupingSet;;;
			OrdinaryGroupingSet = GroupingColumnReference  
			| '('  >> GroupingColumnReferenceList  >> ')' ;;;
			GroupingColumnReference = (ColumnReference >> !CollateClause);;;
			GroupingColumnReferenceList = ((GroupingColumnReference%ch_p(',')));;;
			RollupList =(str_p("ROLLUP"))  >> '('  >> OrdinaryGroupingSetList  >> ')' ;;;
			OrdinaryGroupingSetList = ((OrdinaryGroupingSet%ch_p(',')));;;
			CubeList =(str_p("CUBE"))  >> '('  >> OrdinaryGroupingSetList  >> ')' ;;;
			GroupingSetsSpecification =(str_p("GROUPING"))  >> "SETS"   >> '('  >> GroupingSetList  >> ')' ;;;
			GroupingSetList = ((GroupingSet%ch_p(',')));;;
			GroupingSet = OrdinaryGroupingSet  
			| RollupList  
			| CubeList  
			| GroupingSetsSpecification  
			| EmptyGroupingSet;;;
			EmptyGroupingSet = ch_p('(')  >> ')' ;;;
			HavingClause =(str_p("HAVING")) >> SearchCondition;;;
			WindowClause =(str_p("WINDOW")) >> WindowDefinitionList;;;
			WindowDefinitionList = ((WindowDefinition%ch_p(',')));;;
			WindowDefinition = NewWindowName  >> "AS"  >> WindowSpecification;;;
			NewWindowName = WindowName;;;
			WindowSpecification = ch_p('(') >> WindowSpecificationDetails  >> ')' ;;;
			WindowSpecificationDetails = !(ExistingWindowName >> !WindowPartitionClause >> !WindowOrderClause >> !WindowFrameClause);;;
			ExistingWindowName = WindowName;;;
			WindowPartitionClause =(str_p("PARTITION"))  >> "BY"  >> WindowPartitionColumnReferenceList;;;
			WindowPartitionColumnReferenceList = ((WindowPartitionColumnReference%ch_p(',')));;;
			WindowPartitionColumnReference = (ColumnReference >> !CollateClause);;;
			WindowOrderClause =(str_p("ORDER"))  >> "BY"  >> SortSpecificationList;;;
			WindowFrameClause = (WindowFrameUnits >> WindowFrameExtent >> !WindowFrameExclusion);;;
			WindowFrameUnits =(str_p("ROWS"))  
			| "RANGE" ;;;
			WindowFrameExtent = WindowFrameStart  
			| WindowFrameBetween;;;
			WindowFrameStart =(str_p("UNBOUNDED"))  >> "PRECEDING"   
			| WindowFramePreceding  
			| "CURRENT"   >> "ROW" ;;;
			WindowFramePreceding = UnsignedValueSpecification  >> "PRECEDING" ;;;
			WindowFrameBetween =(str_p("BETWEEN")) >> WindowFrameBound1  >> "AND"  >> WindowFrameBound2;;;
			WindowFrameBound1 = WindowFrameBound;;;
			WindowFrameBound2 = WindowFrameBound;;;
			WindowFrameBound = WindowFrameStart  
			| "UNBOUNDED"   >> "FOLLOWING"   
			| WindowFrameFollowing;;;
			WindowFrameFollowing = UnsignedValueSpecification  >> "FOLLOWING" ;;;
			WindowFrameExclusion =(str_p("EXCLUDE"))  >> "CURRENT"   >> "ROW"   
			| "EXCLUDE"   >> "GROUP"   
			| "EXCLUDE"   >> "TIES"   
			| "EXCLUDE"   >> "NO"   >> "OTHERS" ;;;
			QuerySpecification = ((str_p("SELECT")) >> !SetQuantifier >> SelectList >> TableExpression);;;
			SelectList = ch_p('*')  
			| ((SelectSublist%ch_p(',')));;;
			SelectSublist = DerivedColumn  
			| QualifiedAsterisk;;;
			QualifiedAsterisk = AsteriskedIdentifierChain  >> '.'   >> '*'   
			| AllFieldsReference;;;
			AsteriskedIdentifierChain = ((AsteriskedIdentifier%ch_p('.')));;;
			AsteriskedIdentifier = Identifier;;;
			DerivedColumn = (ValueExpression >> !AsClause);;;
			AsClause = !((str_p("AS")) >> ColumnName);;;
			AllFieldsReference = (ValueExpressionPrimary  >> '.'   >> '*'  >> !(str_p("AS"))  >> '('  >> AllFieldsColumnNameList  >> ')' );;;
			AllFieldsColumnNameList = ColumnNameList;;;
			QueryExpression = !(WithClause >> QueryExpressionBody);;;
			WithClause = ((str_p("WITH")) >> !(str_p("RECURSIVE")) >> WithList);;;
			WithList = ((WithListElement%ch_p(',')));;;
			WithListElement = (QueryName >> !ch_p('(') >> WithColumnList  >> ')'   >> "AS"   >> '('  >> QueryExpression  >> ')'  >> !SearchOrCycleClause);;;
			WithColumnList = ColumnNameList;;;
			QueryExpressionBody = NonJoinQueryExpression  
			| JoinedTable;;;
			NonJoinQueryExpression = NonJoinQueryTerm  
			| (QueryExpressionBody  >> "UNION"  >> !(str_p("ALL"))  
			   | "DISTINCT"  >> !CorrespondingSpec >> QueryTerm)  
			| (QueryExpressionBody  >> "EXCEPT"  >> !(str_p("ALL"))  
			   | "DISTINCT"  >> !CorrespondingSpec >> QueryTerm);;;
			QueryTerm = NonJoinQueryTerm  
			| JoinedTable;;;
			NonJoinQueryTerm = NonJoinQueryPrimary  
			| (QueryTerm  >> "INTERSECT"  >> !(str_p("ALL"))  
			   | "DISTINCT"  >> !CorrespondingSpec >> QueryPrimary);;;
			QueryPrimary = NonJoinQueryPrimary  
			| JoinedTable;;;
			NonJoinQueryPrimary = SimpleTable  
			| '('  >> NonJoinQueryExpression  >> ')' ;;;
			SimpleTable = QuerySpecification  
			| TableValueConstructor  
			| ExplicitTable;;;
			ExplicitTable =(str_p("TABLE")) >> TableOrQueryName;;;
			CorrespondingSpec = ((str_p("CORRESPONDING")) >> !(str_p("BY"))  >> '('  >> CorrespondingColumnList  >> ')' );;;
			CorrespondingColumnList = ColumnNameList;;;
			SearchOrCycleClause = SearchClause  
			| CycleClause  
			| SearchClause >> CycleClause;;;
			SearchClause =(str_p("SEARCH")) >> RecursiveSearchOrder  >> "SET"  >> SequenceColumn;;;
			RecursiveSearchOrder =(str_p("DEPTH"))  >> "FIRST"   >> "BY"  >> SortSpecificationList  
			| "BREADTH"   >> "FIRST"   >> "BY"  >> SortSpecificationList;;;
			SequenceColumn = ColumnName;;;
			CycleClause =(str_p("CYCLE")) >> CycleColumnList  >> "SET"  >> CycleMarkColumn  >> "TO"  >> CycleMarkValue  >> "DEFAULT"  >> NonCycleMarkValue  >> "USING"  >> PathColumn;;;
			CycleColumnList = ((CycleColumn%ch_p(',')));;;
			CycleColumn = ColumnName;;;
			CycleMarkColumn = ColumnName;;;
			PathColumn = ColumnName;;;
			CycleMarkValue = ValueExpression;;;
			NonCycleMarkValue = ValueExpression;;;
			ScalarSubquery = Subquery;;;
			RowSubquery = Subquery;;;
			TableSubquery = Subquery;;;
			Subquery = ch_p('(') >> QueryExpression  >> ')' ;;;
			Predicate = ComparisonPredicate  
			| BetweenPredicate  
			| InPredicate  
			| LikePredicate  
			| SimilarPredicate  
			| NullPredicate  
			| QuantifiedComparisonPredicate  
			| ExistsPredicate  
			| UniquePredicate  
			| NormalizedPredicate  
			| MatchPredicate  
			| OverlapsPredicate  
			| DistinctPredicate  
			| MemberPredicate  
			| SubmultisetPredicate  
			| SetPredicate  
			| TypePredicate;;;
			ComparisonPredicate = RowValuePredicand >> ComparisonPredicatePart2;;;
			ComparisonPredicatePart2 = CompOp >> RowValuePredicand;;;
			CompOp = ch_p('=')  
			| NotEqualsOperator  
			| '<'   
			| '>'   
			| LessThanOrEqualsOperator  
			| GreaterThanOrEqualsOperator;;;
			BetweenPredicate = RowValuePredicand >> BetweenPredicatePart2;;;
			BetweenPredicatePart2 = !((str_p("NOT"))  >> "BETWEEN"  >> !(str_p("ASYMMETRIC"))  
									  | "SYMMETRIC"  >> RowValuePredicand  >> "AND"  >> RowValuePredicand);;;
			InPredicate = RowValuePredicand >> InPredicatePart2;;;
			InPredicatePart2 = !((str_p("NOT"))  >> "IN"  >> InPredicateValue);;;
			InPredicateValue = TableSubquery  
			| '('  >> InValueList  >> ')' ;;;
			InValueList =  RowValueExpression%ch_p(',') ;;;
			LikePredicate = CharacterLikePredicate  
			| OctetLikePredicate;;;
			CharacterLikePredicate = RowValuePredicand >> CharacterLikePredicatePart2;;;
			CharacterLikePredicatePart2 = !((str_p("NOT"))  >> "LIKE"  >> CharacterPattern >> !(str_p("ESCAPE")) >> EscapeCharacter);;;
			CharacterPattern = CharacterValueExpression;;;
			EscapeCharacter = CharacterValueExpression;;;
			OctetLikePredicate = RowValuePredicand >> OctetLikePredicatePart2;;;
			OctetLikePredicatePart2 = !((str_p("NOT"))  >> "LIKE"  >> OctetPattern >> !(str_p("ESCAPE")) >> EscapeOctet);;;
			OctetPattern = BlobValueExpression;;;
			EscapeOctet = BlobValueExpression;;;
			SimilarPredicate = RowValuePredicand >> SimilarPredicatePart2;;;
			SimilarPredicatePart2 = !((str_p("NOT"))  >> "SIMILAR"   >> "TO"  >> SimilarPattern >> !(str_p("ESCAPE")) >> EscapeCharacter);;;
			SimilarPattern = CharacterValueExpression;;;
			RegularExpression = RegularTerm  
			| RegularExpression  >> '|'  >> RegularTerm;;;
			RegularTerm = RegularFactor  
			| RegularTerm >> RegularFactor;;;
			RegularFactor = RegularPrimary  
			| RegularPrimary  >> '*'   
			| RegularPrimary  >> '+'   
			| RegularPrimary  >> '?'   
			| RegularPrimary >> RepeatFactor;;;
			RepeatFactor = (ch_p('[') >> LowValue >> !UpperLimit  >> ']' );;;
			UpperLimit = (ch_p(',') >> !HighValue);;;
			LowValue = uint_p;;;
			HighValue = uint_p;;;
			RegularPrimary = CharacterSpecifier  
			| '%'   
			| RegularCharacterSet  
			| '('  >> RegularExpression  >> ')' ;;;
			CharacterSpecifier = NonEscapedCharacter  
			| EscapedCharacter;;;
			NonEscapedCharacter = nothing_p;;;
			EscapedCharacter = nothing_p;;;
			RegularCharacterSet = ch_p('_')  
			| (ch_p('{') >> +CharacterEnumeration  >> '}' )  
			| (ch_p('{')  >> '^'  >> +CharacterEnumeration  >> '}' )  
			| (ch_p('{') >> +CharacterEnumerationInclude  >> '^'  >> +CharacterEnumerationExclude  >> '}' );;;
			CharacterEnumerationInclude = CharacterEnumeration;;;
			CharacterEnumerationExclude = CharacterEnumeration;;;
			CharacterEnumeration = CharacterSpecifier  
			| CharacterSpecifier  >> '-'  >> CharacterSpecifier  
			| '{'   >> ':'  >> RegularCharacterSetIdentifier  >> ':'   >> '}' ;;;
			RegularCharacterSetIdentifier = Identifier;;;
			NullPredicate = RowValuePredicand >> NullPredicatePart2;;;
			NullPredicatePart2 = ((str_p("IS")) >> !(str_p("NOT"))  >> "NULL" );;;
			QuantifiedComparisonPredicate = RowValuePredicand >> QuantifiedComparisonPredicatePart2;;;
			QuantifiedComparisonPredicatePart2 = CompOp >> Quantifier >> TableSubquery;;;
			Quantifier = All  
			| Some;;;
			All =(str_p("ALL"));;;
			Some =(str_p("SOME"))  
			| "ANY" ;;;
			ExistsPredicate =(str_p("EXISTS")) >> TableSubquery;;;
			UniquePredicate =(str_p("UNIQUE")) >> TableSubquery;;;
			NormalizedPredicate = (StringValueExpression  >> "IS"  >> !(str_p("NOT"))  >> "NORMALIZED" );;;
			MatchPredicate = RowValuePredicand >> MatchPredicatePart2;;;
			MatchPredicatePart2 = ((str_p("MATCH")) >> !(str_p("UNIQUE")) >> !(str_p("SIMPLE"))  
								   | "PARTIAL"   
								   | "FULL"  >> TableSubquery);;;
			OverlapsPredicate = OverlapsPredicatePart1 >> OverlapsPredicatePart2;;;
			OverlapsPredicatePart1 = RowValuePredicand1;;;
			OverlapsPredicatePart2 =(str_p("OVERLAPS")) >> RowValuePredicand2;;;
			RowValuePredicand1 = RowValuePredicand;;;
			RowValuePredicand2 = RowValuePredicand;;;
			DistinctPredicate = RowValuePredicand3 >> DistinctPredicatePart2;;;
			DistinctPredicatePart2 =(str_p("IS"))  >> "DISTINCT"   >> "FROM"  >> RowValuePredicand4;;;
			RowValuePredicand3 = RowValuePredicand;;;
			RowValuePredicand4 = RowValuePredicand;;;
			MemberPredicate = RowValuePredicand >> MemberPredicatePart2;;;
			MemberPredicatePart2 = !((str_p("NOT"))  >> "MEMBER"  >> !(str_p("OF")) >> MultisetValueExpression);;;
			SubmultisetPredicate = RowValuePredicand >> SubmultisetPredicatePart2;;;
			SubmultisetPredicatePart2 = !((str_p("NOT"))  >> "SUBMULTISET"  >> !(str_p("OF")) >> MultisetValueExpression);;;
			SetPredicate = RowValuePredicand >> SetPredicatePart2;;;
			SetPredicatePart2 = ((str_p("IS")) >> !(str_p("NOT")) >> A  >> "SET" );;;
			TypePredicate = RowValuePredicand >> TypePredicatePart2;;;
			TypePredicatePart2 = ((str_p("IS")) >> !(str_p("NOT"))  >> "OF"   >> '('  >> TypeList  >> ')' );;;
			TypeList = ((UserDefinedTypeSpecification%ch_p(',')));;;
			UserDefinedTypeSpecification = InclusiveUserDefinedTypeSpecification  
			| ExclusiveUserDefinedTypeSpecification;;;
			InclusiveUserDefinedTypeSpecification = PathResolvedUserDefinedTypeName;;;
			ExclusiveUserDefinedTypeSpecification =(str_p("ONLY")) >> PathResolvedUserDefinedTypeName;;;
			SearchCondition = BooleanValueExpression;;;
			IntervalQualifier = StartField  >> "TO"  >> EndField  
			| SingleDatetimeField;;;
			StartField = (NonSecondPrimaryDatetimeField >> !ch_p('(') >> IntervalLeadingFieldPrecision  >> ')' );;;
			EndField = NonSecondPrimaryDatetimeField  
			| ((str_p("SECOND")) >> !ch_p('(') >> IntervalFractionalSecondsPrecision  >> ')' );;;
			SingleDatetimeField = (NonSecondPrimaryDatetimeField >> !ch_p('(') >> IntervalLeadingFieldPrecision  >> ')' )  
			| ((str_p("SECOND")) >> !(ch_p('(') >> IntervalLeadingFieldPrecision >> !ch_p(',') >> IntervalFractionalSecondsPrecision  >> ')' ));;;
			PrimaryDatetimeField = NonSecondPrimaryDatetimeField  
			| "SECOND" ;;;
			NonSecondPrimaryDatetimeField =(str_p("YEAR"))  
			| "MONTH"   
			| "DAY"   
			| "HOUR"   
			| "MINUTE" ;;;
			IntervalFractionalSecondsPrecision = uint_p;;;
			IntervalLeadingFieldPrecision = uint_p;;;
			LanguageClause =(str_p("LANGUAGE")) >> LanguageName;;;
			LanguageName =(str_p("ADA"))  
			|('C')  
			| "COBOL"   
			| "FORTRAN"   
			| "MUMPS"   
			| "PASCAL"   
			| "PLI"   
			| "SQL" ;;;
			PathSpecification =(str_p("PATH")) >> SchemaNameList;;;
			SchemaNameList = ((SchemaName%ch_p(',')));;;
			RoutineInvocation = RoutineName >> SQLArgumentList;;;
			RoutineName = !(SchemaName  >> '.'  >> QualifiedIdentifier);;;
			SQLArgumentList = (ch_p('(') >> !((SQLArgument%ch_p(',')))  >> ')' );;;
			SQLArgument = ValueExpression  
			| GeneralizedExpression  
			| TargetSpecification;;;
			GeneralizedExpression = ValueExpression  >> "AS"  >> PathResolvedUserDefinedTypeName;;;
			CharacterSetSpecification = StandardCharacterSetName  
			| ImplementationDefinedCharacterSetName  
			| UserDefinedCharacterSetName;;;
			StandardCharacterSetName = CharacterSetName;;;
			ImplementationDefinedCharacterSetName = CharacterSetName;;;
			UserDefinedCharacterSetName = CharacterSetName;;;
			SpecificRoutineDesignator =(str_p("SPECIFIC")) >> RoutineType >> SpecificName  
			| (RoutineType >> MemberName >> !(str_p("FOR")) >> SchemaResolvedUserDefinedTypeName);;;
			RoutineType =(str_p("ROUTINE"))  
			| "FUNCTION"   
			| "PROCEDURE"   
			| !((str_p("INSTANCE"))  
				| "STATIC"   
				| CONSTRUCTOR  >> "METHOD" );;;
			MemberName = (MemberNameAlternatives >> !DataTypeList);;;
			MemberNameAlternatives = SchemaQualifiedRoutineName  
			| MethodName;;;
			DataTypeList = (ch_p('(') >> !((DataType%ch_p(',')))  >> ')' );;;
			CollateClause =(str_p("COLLATE")) >> CollationName;;;
			ConstraintNameDefinition =(str_p("CONSTRAINT")) >> ConstraintName;;;
			ConstraintCharacteristics = (ConstraintCheckTime >> !!((str_p("NOT"))  >> "DEFERRABLE" ))  
			| !((str_p("NOT"))  >> "DEFERRABLE"  >> !ConstraintCheckTime);;;
			ConstraintCheckTime =(str_p("INITIALLY"))  >> "DEFERRED"   
			| "INITIALLY"   >> "IMMEDIATE" ;;;
			AggregateFunction = ((str_p("COUNT"))  >> '('   >> '*'   >> ')'  >> !FilterClause)  
			| (GeneralSetFunction >> !FilterClause)  
			| (BinarySetFunction >> !FilterClause)  
			| (OrderedSetFunction >> !FilterClause);;;
			GeneralSetFunction = (SetFunctionType  >> '('  >> !SetQuantifier >> ValueExpression  >> ')' );;;
			SetFunctionType = ComputationalOperation;;;
			ComputationalOperation =(str_p("AVG"))  
			| "MAX"   
			| "MIN"   
			| "SUM"   
			| "EVERY"   
			| "ANY"   
			| "SOME"   
			| "COUNT"   
			| "STDDEV_POP"   
			| "STDDEV_SAMP"   
			| "VAR_SAMP"   
			| "VAR_POP"   
			| "COLLECT"   
			| "FUSION"   
			| "INTERSECTION" ;;;
			SetQuantifier =(str_p("DISTINCT"))  
			| "ALL" ;;;
			FilterClause =(str_p("FILTER"))  >> '('   >> "WHERE"  >> SearchCondition  >> ')' ;;;
			BinarySetFunction = BinarySetFunctionType  >> '('  >> DependentVariableExpression  >> ','  >> IndependentVariableExpression  >> ')' ;;;
			BinarySetFunctionType =(str_p("COVAR_POP"))  
			| "COVAR_SAMP"   
			| "CORR"   
			| "REGR_SLOPE"   
			| "REGR_INTERCEPT"   
			| "REGR_COUNT"   
			| "REGR_R2"   
			| "REGR_AVGX"   
			| "REGR_AVGY"   
			| "REGR_SXX"   
			| "REGR_SYY"
			| "REGR_SXY" ;;;
			DependentVariableExpression = NumericValueExpression;;;
			IndependentVariableExpression = NumericValueExpression;;;
			OrderedSetFunction = HypotheticalSetFunction  
			| InverseDistributionFunction;;;
			HypotheticalSetFunction = RankFunctionType  >> '('  >> HypotheticalSetFunctionValueExpressionList  >> ')'  >> WithinGroupSpecification;;;
			WithinGroupSpecification =(str_p("WITHIN"))  >> "GROUP"   >> '('   >> "ORDER"   >> "BY"  >> SortSpecificationList  >> ')' ;;;
			HypotheticalSetFunctionValueExpressionList = ((ValueExpression%ch_p(',')));;;
			InverseDistributionFunction = InverseDistributionFunctionType  >> '('  >> InverseDistributionFunctionArgument  >> ')'  >> WithinGroupSpecification;;;
			InverseDistributionFunctionArgument = NumericValueExpression;;;
			InverseDistributionFunctionType =(str_p("PERCENTILE_CONT"))  
			| "PERCENTILE_DISC" ;;;
			SortSpecificationList = ((SortSpecification%ch_p(',')));;;
			SortSpecification = (SortKey >> !OrderingSpecification >> !NullOrdering);;;
			SortKey = ValueExpression;;;
			OrderingSpecification =(str_p("ASC"))  
			| "DESC" ;;;
			NullOrdering =(str_p("NULLS"))  >> "FIRST"   
			| "NULLS"   >> "LAST" ;;;
			SchemaDefinition = ((str_p("CREATE"))  >> "SCHEMA"  >> SchemaNameClause >> !SchemaCharacterSetOrPath >> *SchemaElement);;;
			SchemaCharacterSetOrPath = SchemaCharacterSetSpecification  
			| SchemaPathSpecification  
			| SchemaCharacterSetSpecification >> SchemaPathSpecification  
			| SchemaPathSpecification >> SchemaCharacterSetSpecification;;;
			SchemaNameClause = SchemaName  
			| "AUTHORIZATION"  >> SchemaAuthorizationIdentifier  
			| SchemaName  >> "AUTHORIZATION"  >> SchemaAuthorizationIdentifier;;;
			SchemaAuthorizationIdentifier = AuthorizationIdentifier;;;
			SchemaCharacterSetSpecification =(str_p("DEFAULT"))  >> "CHARACTER"   >> "SET"  >> CharacterSetSpecification;;;
			SchemaPathSpecification = PathSpecification;;;
			SchemaElement = TableDefinition  
			| ViewDefinition  
			| DomainDefinition  
			| CharacterSetDefinition  
			| CollationDefinition  
			| TransliterationDefinition  
			| AssertionDefinition  
			| TriggerDefinition  
			| UserDefinedTypeDefinition  
			| UserDefinedCastDefinition  
			| UserDefinedOrderingDefinition  
			| TransformDefinition  
			| SchemaRoutine  
			| SequenceGeneratorDefinition  
			| GrantStatement  
			| RoleDefinition;;;
			DropSchemaStatement =(str_p("DROP"))  >> "SCHEMA"  >> SchemaName >> DropBehavior;;;
			DropBehavior =(str_p("CASCADE"))  
			| RESTRICT;;;
			TableDefinition = ((str_p("CREATE")) >> !TableScope  >> "TABLE"  >> TableName >> TableContentsSource >> !(str_p("ON"))  >> "COMMIT"  >> TableCommitAction  >> "ROWS" );;;
			TableContentsSource = TableElementList  
			| ((str_p("OF")) >> PathResolvedUserDefinedTypeName >> !SubtableClause >> !TableElementList)  
			| AsSubqueryClause;;;
			TableScope = GlobalOrLocal  >> "TEMPORARY" ;;;
			GlobalOrLocal =(str_p("GLOBAL"))  
			| "LOCAL" ;;;
			TableCommitAction =(str_p("PRESERVE"))  
			| "DELETE" ;;;
			TableElementList = (ch_p('(') >> (TableElement%ch_p(','))  >> ')' );;;
			TableElement = ColumnDefinition  
			| TableConstraintDefinition  
			| LikeClause  
			| SelfReferencingColumnSpecification  
			| ColumnOptions;;;
			SelfReferencingColumnSpecification =(str_p("REF"))  >> "IS"  >> SelfReferencingColumnName >> ReferenceGeneration;;;
			ReferenceGeneration =(str_p("SYSTEM")) >> "GENERATED"  
			| "USER"  >> "GENERATED"  
			| "DERIVED" ;;;
			SelfReferencingColumnName = ColumnName;;;
			ColumnOptions = ColumnName  >> "WITH"   >> "OPTIONS"  >> ColumnOptionList;;;
			ColumnOptionList = !(ScopeClause >> !DefaultClause >> *ColumnConstraintDefinition);;;
			SubtableClause =(str_p("UNDER")) >> SupertableClause;;;
			SupertableClause = SupertableName;;;
			SupertableName = TableName;;;
			LikeClause = ((str_p("LIKE")) >> TableName >> !LikeOptions);;;
			LikeOptions = IdentityOption  
			| ColumnDefaultOption;;;
			IdentityOption =(str_p("INCLUDING"))  >> "IDENTITY"   
			| "EXCLUDING"   >> "IDENTITY" ;;;
			ColumnDefaultOption =(str_p("INCLUDING"))  >> "DEFAULTS"   
			| "EXCLUDING"   >> "DEFAULTS" ;;;
			AsSubqueryClause = !(ch_p('(') >> ColumnNameList  >> ')'   >> "AS"  >> Subquery >> WithOrWithoutData);;;
			WithOrWithoutData =(str_p("WITH"))  >> "NO"   >> "DATA"   
			| "WITH"   >> "DATA" ;;;
			ColumnDefinition = (ColumnName >> !DataType  
								| DomainName >> !ReferenceScopeCheck >> !DefaultClause  
								| IdentityColumnSpecification  
								| GenerationClause >> *ColumnConstraintDefinition >> !CollateClause);;;
			ColumnConstraintDefinition = !(ConstraintNameDefinition >> ColumnConstraint >> !ConstraintCharacteristics);;;
			ColumnConstraint =(str_p("NOT"))  >> "NULL"   
			| UniqueSpecification  
			| ReferencesSpecification  
			| CheckConstraintDefinition;;;
			ReferenceScopeCheck = ((str_p("REFERENCES"))  >> "ARE"  >> !(str_p("NOT"))  >> "CHECKED"  >> !(str_p("ON"))  >> "DELETE"  >> ReferenceScopeCheckAction);;;
			ReferenceScopeCheckAction = ReferentialAction;;;
			IdentityColumnSpecification = ("GENERATED"  >> "ALWAYS"   
										   | "BY"   >> "DEFAULT"   >> "AS"   >> "IDENTITY"  >> !ch_p('(') >> CommonSequenceGeneratorOptions  >> ')' );;;
			GenerationClause = GenerationRule  >> "AS"  >> GenerationExpression;;;
			GenerationRule = "GENERATED"  >> "ALWAYS" ;;;
			GenerationExpression = ch_p('(') >> ValueExpression  >> ')' ;;;
			DefaultClause =(str_p("DEFAULT")) >> DefaultOption;;;
			DefaultOption = Literal  
			| DatetimeValueFunction  
			| "USER"   
			| "CURRENT_USER"   
			| "CURRENT_ROLE"   
			| "SESSION_USER"   
			| "SYSTEM_USER"   
			| "CURRENT_PATH"   
			| ImplicitlyTypedValueSpecification;;;
			TableConstraintDefinition = !(ConstraintNameDefinition >> TableConstraint >> !ConstraintCharacteristics);;;
			TableConstraint = UniqueConstraintDefinition  
			| ReferentialConstraintDefinition  
			| CheckConstraintDefinition;;;
			UniqueConstraintDefinition = UniqueSpecification  >> '('  >> UniqueColumnList  >> ')'   
			| ((str_p("UNIQUE"))  >> "VALUE" );;;
			UniqueSpecification =(str_p("UNIQUE"))  
			| "PRIMARY"   >> "KEY" ;;;
			UniqueColumnList = ColumnNameList;;;
			ReferentialConstraintDefinition =(str_p("FOREIGN"))  >> "KEY"   >> '('  >> ReferencingColumns  >> ')'  >> ReferencesSpecification;;;
			ReferencesSpecification = ((str_p("REFERENCES")) >> ReferencedTableAndColumns >> !(str_p("MATCH")) >> MatchType >> !ReferentialTriggeredAction);;;
			MatchType =(str_p("FULL"))  
			| "PARTIAL"   
			| "SIMPLE" ;;;
			ReferencingColumns = ReferenceColumnList;;;
			ReferencedTableAndColumns = (TableName >> !ch_p('(') >> ReferenceColumnList  >> ')' );;;
			ReferenceColumnList = ColumnNameList;;;
			ReferentialTriggeredAction = (UpdateRule >> !DeleteRule)  
			| (DeleteRule >> !UpdateRule);;;
			UpdateRule =(str_p("ON"))  >> "UPDATE"  >> ReferentialAction;;;
			DeleteRule =(str_p("ON"))  >> "DELETE"  >> ReferentialAction;;;
			ReferentialAction =(str_p("CASCADE"))  
			| "SET"   >> "NULL"   
			| "SET"   >> "DEFAULT"   
			| RESTRICT  
			| "NO"   >> "ACTION" ;;;
			CheckConstraintDefinition =(str_p("CHECK"))  >> '('  >> SearchCondition  >> ')' ;;;
			AlterTableStatement =(str_p("ALTER"))  >> "TABLE"  >> TableName >> AlterTableAction;;;
			AlterTableAction = AddColumnDefinition  
			| AlterColumnDefinition  
			| DropColumnDefinition  
			| AddTableConstraintDefinition  
			| DropTableConstraintDefinition;;;
			AddColumnDefinition = ((str_p("ADD")) >> !(str_p("COLUMN")) >> ColumnDefinition);;;
			AlterColumnDefinition = ((str_p("ALTER")) >> !(str_p("COLUMN")) >> ColumnName >> AlterColumnAction);;;
			AlterColumnAction = SetColumnDefaultClause  
			| DropColumnDefaultClause  
			| AddColumnScopeClause  
			| DropColumnScopeClause  
			| AlterIdentityColumnSpecification;;;
			SetColumnDefaultClause =(str_p("SET")) >> DefaultClause;;;
			DropColumnDefaultClause =(str_p("DROP"))  >> "DEFAULT" ;;;
			AddColumnScopeClause =(str_p("ADD")) >> ScopeClause;;;
			DropColumnScopeClause =(str_p("DROP")) >> "SCOPE" >> DropBehavior;;;
			AlterIdentityColumnSpecification = +AlterIdentityColumnOption;;;
			AlterIdentityColumnOption = AlterSequenceGeneratorRestartOption  
			| "SET"  >> BasicSequenceGeneratorOption;;;
			DropColumnDefinition = ((str_p("DROP")) >> !(str_p("COLUMN")) >> ColumnName >> DropBehavior);;;
			AddTableConstraintDefinition =(str_p("ADD")) >> TableConstraintDefinition;;;
			DropTableConstraintDefinition =(str_p("DROP"))  >> "CONSTRAINT"  >> ConstraintName >> DropBehavior;;;
			DropTableStatement =(str_p("DROP"))  >> "TABLE"  >> TableName >> DropBehavior;;;
			ViewDefinition = ((str_p("CREATE")) >> !(str_p("RECURSIVE"))  >> "VIEW"  >> TableName >> ViewSpecification  >> "AS"  >> QueryExpression >> !((str_p("WITH")) >> !LevelsClause  >> "CHECK"   >> "OPTION" ));;;
			ViewSpecification = RegularViewSpecification  
			| ReferenceableViewSpecification;;;
			RegularViewSpecification = !(ch_p('(') >> ViewColumnList  >> ')' );;;
			ReferenceableViewSpecification = ((str_p("OF")) >> PathResolvedUserDefinedTypeName >> !SubviewClause >> !ViewElementList);;;
			SubviewClause =(str_p("UNDER")) >> TableName;;;
			ViewElementList = (ch_p('(') >> (ViewElement%ch_p(','))  >> ')' );;;
			ViewElement = SelfReferencingColumnSpecification  
			| ViewColumnOption;;;
			ViewColumnOption = ColumnName  >> "WITH"   >> "OPTIONS"  >> ScopeClause;;;
			LevelsClause =(str_p("CASCADED"))  
			| "LOCAL" ;;;
			ViewColumnList = ColumnNameList;;;
			DropViewStatement =(str_p("DROP"))  >> "VIEW"  >> TableName >> DropBehavior;;;
			DomainDefinition = ((str_p("CREATE"))  >> "DOMAIN"  >> DomainName >> !(str_p("AS")) >> DataType >> !DefaultClause >> *DomainConstraint >> !CollateClause);;;
			DomainConstraint = !(ConstraintNameDefinition >> CheckConstraintDefinition >> !ConstraintCharacteristics);;;
			AlterDomainStatement =(str_p("ALTER"))  >> "DOMAIN"  >> DomainName >> AlterDomainAction;;;
			AlterDomainAction = SetDomainDefaultClause  
			| DropDomainDefaultClause  
			| AddDomainConstraintDefinition  
			| DropDomainConstraintDefinition;;;
			SetDomainDefaultClause =(str_p("SET")) >> DefaultClause;;;
			DropDomainDefaultClause =(str_p("DROP"))  >> "DEFAULT" ;;;
			AddDomainConstraintDefinition =(str_p("ADD")) >> DomainConstraint;;;
			DropDomainConstraintDefinition =(str_p("DROP"))  >> "CONSTRAINT"  >> ConstraintName;;;
			DropDomainStatement =(str_p("DROP"))  >> "DOMAIN"  >> DomainName >> DropBehavior;;;
			CharacterSetDefinition = ((str_p("CREATE"))  >> "CHARACTER"   >> "SET"  >> CharacterSetName >> !(str_p("AS")) >> CharacterSetSource >> !CollateClause);;;
			CharacterSetSource =(str_p("GET")) >> CharacterSetSpecification;;;
			DropCharacterSetStatement =(str_p("DROP"))  >> "CHARACTER"   >> "SET"  >> CharacterSetName;;;
			CollationDefinition = ((str_p("CREATE"))  >> "COLLATION"  >> CollationName  >> "FOR"  >> CharacterSetSpecification  >> "FROM"  >> ExistingCollationName >> !PadCharacteristic);;;
			ExistingCollationName = CollationName;;;
			PadCharacteristic =(str_p("NO"))  >> "PAD"   
			| "PAD"   >> "SPACE" ;;;
			DropCollationStatement =(str_p("DROP"))  >> "COLLATION"  >> CollationName >> DropBehavior;;;
			TransliterationDefinition =(str_p("CREATE"))  >> "TRANSLATION"  >> TransliterationName  >> "FOR"  >> SourceCharacterSetSpecification  >> "TO"  >> TargetCharacterSetSpecification  >> "FROM"  >> TransliterationSource;;;
			SourceCharacterSetSpecification = CharacterSetSpecification;;;
			TargetCharacterSetSpecification = CharacterSetSpecification;;;
			TransliterationSource = ExistingTransliterationName  
			| TransliterationRoutine;;;
			ExistingTransliterationName = TransliterationName;;;
			TransliterationRoutine = SpecificRoutineDesignator;;;
			DropTransliterationStatement =(str_p("DROP"))  >> "TRANSLATION"  >> TransliterationName;;;
			AssertionDefinition = ((str_p("CREATE"))  >> "ASSERTION"  >> ConstraintName  >> "CHECK"   >> '('  >> SearchCondition  >> ')'  >> !ConstraintCharacteristics);;;
			DropAssertionStatement =(str_p("DROP"))  >> "ASSERTION"  >> ConstraintName;;;
			TriggerDefinition = ((str_p("CREATE"))  >> "TRIGGER"  >> TriggerName >> TriggerActionTime >> TriggerEvent  >> "ON"  >> TableName >> !(str_p("REFERENCING")) >> OldOrNewValuesAliasList >> TriggeredAction);;;
			TriggerActionTime =(str_p("BEFORE"))  
			| "AFTER" ;;;
			TriggerEvent =(str_p("INSERT"))  
			| "DELETE"   
			| ((str_p("UPDATE")) >> !(str_p("OF")) >> TriggerColumnList);;;
			TriggerColumnList = ColumnNameList;;;
			TriggeredAction = !(((str_p("FOR"))  >> "EACH"   >> "ROW"   
								 | "STATEMENT" ) >> !(str_p("WHEN"))  >> '('  >> SearchCondition  >> ')'  >> TriggeredSQLStatement);;;
			TriggeredSQLStatement = SQLProcedureStatement  
			| ((str_p("BEGIN"))  >> "ATOMIC"  >> +SQLProcedureStatement  >> ';'   >> "END" );;;
			OldOrNewValuesAliasList = +OldOrNewValuesAlias;;;
			OldOrNewValuesAlias = ((str_p("OLD")) >> !(str_p("ROW")) >> !(str_p("AS")) >> OldValuesCorrelationName)  
			| ((str_p("NEW")) >> !(str_p("ROW")) >> !(str_p("AS")) >> NewValuesCorrelationName)  
			| ((str_p("OLD"))  >> "TABLE"  >> !(str_p("AS")) >> OldValuesTableAlias)  
			| ((str_p("NEW"))  >> "TABLE"  >> !(str_p("AS")) >> NewValuesTableAlias);;;
			OldValuesTableAlias = Identifier;;;
			NewValuesTableAlias = Identifier;;;
			OldValuesCorrelationName = CorrelationName;;;
			NewValuesCorrelationName = CorrelationName;;;
			DropTriggerStatement =(str_p("DROP"))  >> "TRIGGER"  >> TriggerName;;;
			UserDefinedTypeDefinition =(str_p("CREATE"))  >> "TYPE"  >> UserDefinedTypeBody;;;
			UserDefinedTypeBody = (SchemaResolvedUserDefinedTypeName >> !SubtypeClause >> !(str_p("AS")) >> Representation >> !UserDefinedTypeOptionList >> !MethodSpecificationList);;;
			UserDefinedTypeOptionList = (UserDefinedTypeOption >> *UserDefinedTypeOption);;;
			UserDefinedTypeOption = InstantiableClause  
			| Finality  
			| ReferenceTypeSpecification  
			| RefCastOption  
			| CastOption;;;
			SubtypeClause =(str_p("UNDER")) >> SupertypeName;;;
			SupertypeName = PathResolvedUserDefinedTypeName;;;
			Representation = PredefinedType  
			| MemberList;;;
			MemberList = (ch_p('(') >> (Member%ch_p(','))  >> ')' );;;
			Member = AttributeDefinition;;;
			InstantiableClause =(str_p("INSTANTIABLE"))  
			| "NOT"   >> "INSTANTIABLE" ;;;
			Finality =(str_p("FINAL"))  
			| "NOT"   >> "FINAL" ;;;
			ReferenceTypeSpecification = UserDefinedRepresentation  
			| DerivedRepresentation  
			| SystemGeneratedRepresentation;;;
			UserDefinedRepresentation =(str_p("REF"))  >> "USING"  >> PredefinedType;;;
			DerivedRepresentation =(str_p("REF"))  >> "FROM"  >> ListOfAttributes;;;
			SystemGeneratedRepresentation =(str_p("REF"))  >> "IS"   >> "SYSTEM"  >> "GENERATED";;;
			RefCastOption = !(CastToRef >> !CastToType);;;
			CastToRef =(str_p("CAST"))  >> '('   >> "SOURCE"   >> "AS"   >> "REF"   >> ')'   >> "WITH"  >> CastToRefIdentifier;;;
			CastToRefIdentifier = Identifier;;;
			CastToType =(str_p("CAST"))  >> '('   >> "REF"   >> "AS"   >> "SOURCE"   >> ')'   >> "WITH"  >> CastToTypeIdentifier;;;
			CastToTypeIdentifier = Identifier;;;
			ListOfAttributes = (ch_p('(') >> (AttributeName%ch_p(','))  >> ')' );;;
			CastOption = !(CastToDistinct >> !CastToSource);;;
			CastToDistinct =(str_p("CAST"))  >> '('   >> "SOURCE"   >> "AS"   >> "DISTINCT"   >> ')'   >> "WITH"  >> CastToDistinctIdentifier;;;
			CastToDistinctIdentifier = Identifier;;;
			CastToSource =(str_p("CAST"))  >> '('   >> "DISTINCT"   >> "AS"   >> "SOURCE"   >> ')'   >> "WITH"  >> CastToSourceIdentifier;;;
			CastToSourceIdentifier = Identifier;;;
			MethodSpecificationList = ((MethodSpecification%ch_p(',')));;;
			MethodSpecification = OriginalMethodSpecification  
			| OverridingMethodSpecification;;;
			OriginalMethodSpecification = (PartialMethodSpecification >> !(str_p("SELF"))  >> "AS"   >> "RESULT"  >> !(str_p("SELF"))  >> "AS"   >> "LOCATOR"  >> !MethodCharacteristics);;;
			OverridingMethodSpecification =(str_p("OVERRIDING")) >> PartialMethodSpecification;;;
			PartialMethodSpecification = !((str_p("INSTANCE"))  
										   | "STATIC"   
										   | CONSTRUCTOR  >> "METHOD"  >> MethodName >> SQLParameterDeclarationList >> ReturnsClause >> !(str_p("SPECIFIC")) >> SpecificMethodName);;;
			SpecificMethodName = !(SchemaName  >> '.'  >> QualifiedIdentifier);;;
			MethodCharacteristics = +MethodCharacteristic;;;
			MethodCharacteristic = LanguageClause  
			| ParameterStyleClause  
			| DeterministicCharacteristic  
			| SQLDataAccessIndication  
			| NullCallClause;;;
			AttributeDefinition = (AttributeName >> DataType >> !ReferenceScopeCheck >> !AttributeDefault >> !CollateClause);;;
			AttributeDefault = DefaultClause;;;
			AlterTypeStatement =(str_p("ALTER"))  >> "TYPE"  >> SchemaResolvedUserDefinedTypeName >> AlterTypeAction;;;
			AlterTypeAction = AddAttributeDefinition  
			| DropAttributeDefinition  
			| AddOriginalMethodSpecification  
			| AddOverridingMethodSpecification  
			| DropMethodSpecification;;;
			AddAttributeDefinition =(str_p("ADD"))  >> "ATTRIBUTE"  >> AttributeDefinition;;;
			DropAttributeDefinition =(str_p("DROP"))  >> "ATTRIBUTE"  >> AttributeName >> RESTRICT;;;
			AddOriginalMethodSpecification =(str_p("ADD")) >> OriginalMethodSpecification;;;
			AddOverridingMethodSpecification =(str_p("ADD")) >> OverridingMethodSpecification;;;
			DropMethodSpecification =(str_p("DROP")) >> SpecificMethodSpecificationDesignator >> RESTRICT;;;
			SpecificMethodSpecificationDesignator = !((str_p("INSTANCE"))  
													  | "STATIC"   
													  | CONSTRUCTOR  >> "METHOD"  >> MethodName >> DataTypeList);;;
			DropDataTypeStatement =(str_p("DROP"))  >> "TYPE"  >> SchemaResolvedUserDefinedTypeName >> DropBehavior;;;
			SQLInvokedRoutine = SchemaRoutine;;;
			SchemaRoutine = SchemaProcedure  
			| SchemaFunction;;;
			SchemaProcedure =(str_p("CREATE")) >> SQLInvokedProcedure;;;
			SchemaFunction =(str_p("CREATE")) >> SQLInvokedFunction;;;
			SQLInvokedProcedure =(str_p("PROCEDURE")) >> SchemaQualifiedRoutineName >> SQLParameterDeclarationList >> RoutineCharacteristics >> RoutineBody;;;
			SQLInvokedFunction = (FunctionSpecification  
								  | MethodSpecificationDesignator >> RoutineBody);;;
			SQLParameterDeclarationList = (ch_p('(') >> !((SQLParameterDeclaration%ch_p(',')))  >> ')' );;;
			SQLParameterDeclaration = !(ParameterMode >> !SQLParameterName >> ParameterType >> !(str_p("RESULT")));;;
			ParameterMode =(str_p("IN"))  
			| "OUT"   
			| "INOUT" ;;;
			ParameterType = (DataType >> !LocatorIndication);;;
			LocatorIndication =(str_p("AS"))  >> "LOCATOR" ;;;
			FunctionSpecification = ((str_p("FUNCTION")) >> SchemaQualifiedRoutineName >> SQLParameterDeclarationList >> ReturnsClause >> RoutineCharacteristics >> !DispatchClause);;;
			MethodSpecificationDesignator =(str_p("SPECIFIC"))  >> "METHOD"  >> SpecificMethodName  
			| !((str_p("INSTANCE"))  
				| "STATIC"   
				| CONSTRUCTOR  >> "METHOD"  >> MethodName >> SQLParameterDeclarationList >> !ReturnsClause  >> "FOR"  >> SchemaResolvedUserDefinedTypeName);;;
			RoutineCharacteristics = *(RoutineCharacteristic);;;
			RoutineCharacteristic = LanguageClause  
			| ParameterStyleClause  
			| "SPECIFIC"  >> SpecificName  
			| DeterministicCharacteristic  
			| SQLDataAccessIndication  
			| NullCallClause  
			| DynamicResultSetsCharacteristic  
			| SavepointLevelIndication;;;
			SavepointLevelIndication =(str_p("NEW"))  >> "SAVEPOINT"   >> "LEVEL"   
			| "OLD"   >> "SAVEPOINT"   >> "LEVEL" ;;;
			DynamicResultSetsCharacteristic =(str_p("DYNAMIC"))  >> "RESULT"   >> "SETS"  >> MaximumDynamicResultSets;;;
			ParameterStyleClause =(str_p("PARAMETER"))  >> "STYLE"  >> ParameterStyle;;;
			DispatchClause =(str_p("STATIC"))  >> "DISPATCH" ;;;
			ReturnsClause =(str_p("RETURNS")) >> ReturnsType;;;
			ReturnsType = (ReturnsDataType >> !ResultCast)  
			| ReturnsTableType;;;
			ReturnsTableType =(str_p("TABLE")) >> TableFunctionColumnList;;;
			TableFunctionColumnList = (ch_p('(') >> (TableFunctionColumnListElement%ch_p(','))  >> ')' );;;
			TableFunctionColumnListElement = ColumnName >> DataType;;;
			ResultCast =(str_p("CAST"))  >> "FROM"  >> ResultCastFromType;;;
			ResultCastFromType = (DataType >> !LocatorIndication);;;
			ReturnsDataType = (DataType >> !LocatorIndication);;;
			RoutineBody = SQLRoutineSpec  
			| ExternalBodyReference;;;
			SQLRoutineSpec = !(RightsClause >> SQLRoutineBody);;;
			RightsClause =(str_p("SQL"))  >> "SECURITY"   >> "INVOKER"   
			| "SQL"   >> "SECURITY"   >> "DEFINER" ;;;
			SQLRoutineBody = SQLProcedureStatement;;;
			ExternalBodyReference = ((str_p("EXTERNAL")) >> !(str_p("NAME")) >> ExternalRoutineName >> !ParameterStyleClause >> !TransformGroupSpecification >> !ExternalSecurityClause);;;
			ExternalSecurityClause =(str_p("EXTERNAL"))  >> "SECURITY"   >> "DEFINER"   
			| "EXTERNAL"   >> "SECURITY"   >> "INVOKER"   
			| "EXTERNAL"   >> "SECURITY"   >> "IMPLEMENTATION"   >> "DEFINED" ;;;
			ParameterStyle =(str_p("SQL"))  
			| "GENERAL" ;;;
			DeterministicCharacteristic =(str_p("DETERMINISTIC"))  
			| "NOT"   >> "DETERMINISTIC" ;;;
			SQLDataAccessIndication =(str_p("NO"))  >> "SQL"   
			| "CONTAINS"   >> "SQL"   
			| "READS"   >> "SQL"   >> "DATA"   
			| "MODIFIES"   >> "SQL"   >> "DATA" ;;;
			NullCallClause =(str_p("RETURNS"))  >> "NULL"   >> "ON"   >> "NULL"   >> "INPUT"   
			| "CALLED"   >> "ON"   >> "NULL"   >> "INPUT" ;;;
			MaximumDynamicResultSets = uint_p;;;
			TransformGroupSpecification = ((str_p("TRANSFORM"))  >> "GROUP"  >> SingleGroupSpecification  
										   | MultipleGroupSpecification);;;
			SingleGroupSpecification = GroupName;;;
			MultipleGroupSpecification = ((GroupSpecification%ch_p(',')));;;
			GroupSpecification = GroupName  >> "FOR"   >> "TYPE"  >> PathResolvedUserDefinedTypeName;;;
			AlterRoutineStatement =(str_p("ALTER")) >> SpecificRoutineDesignator >> AlterRoutineCharacteristics >> AlterRoutineBehavior;;;
			AlterRoutineCharacteristics = +AlterRoutineCharacteristic;;;
			AlterRoutineCharacteristic = LanguageClause  
			| ParameterStyleClause  
			| SQLDataAccessIndication  
			| NullCallClause  
			| DynamicResultSetsCharacteristic  
			| "NAME"  >> ExternalRoutineName;;;
			AlterRoutineBehavior = RESTRICT;;;
			DropRoutineStatement =(str_p("DROP")) >> SpecificRoutineDesignator >> DropBehavior;;;
			UserDefinedCastDefinition = ((str_p("CREATE"))  >> "CAST"   >> '('  >> SourceDataType  >> "AS"  >> TargetDataType  >> ')'   >> "WITH"  >> CastFunction >> !(str_p("AS"))  >> "ASSIGNMENT" );;;
			CastFunction = SpecificRoutineDesignator;;;
			SourceDataType = DataType;;;
			TargetDataType = DataType;;;
			DropUserDefinedCastStatement =(str_p("DROP"))  >> "CAST"   >> '('  >> SourceDataType  >> "AS"  >> TargetDataType  >> ')'  >> DropBehavior;;;
			UserDefinedOrderingDefinition =(str_p("CREATE"))  >> "ORDERING"   >> "FOR"  >> SchemaResolvedUserDefinedTypeName >> OrderingForm;;;
			OrderingForm = EqualsOrderingForm  
			| FullOrderingForm;;;
			EqualsOrderingForm =(str_p("EQUALS"))  >> "ONLY"   >> "BY"  >> OrderingCategory;;;
			FullOrderingForm =(str_p("ORDER"))  >> "FULL"   >> "BY"  >> OrderingCategory;;;
			OrderingCategory = RelativeCategory  
			| MapCategory  
			| StateCategory;;;
			RelativeCategory =(str_p("RELATIVE"))  >> "WITH"  >> RelativeFunctionSpecification;;;
			MapCategory =(str_p("MAP"))  >> "WITH"  >> MapFunctionSpecification;;;
			StateCategory = ((str_p("STATE")) >> !SpecificName);;;
			RelativeFunctionSpecification = SpecificRoutineDesignator;;;
			MapFunctionSpecification = SpecificRoutineDesignator;;;
			DropUserDefinedOrderingStatement =(str_p("DROP"))  >> "ORDERING"   >> "FOR"  >> SchemaResolvedUserDefinedTypeName >> DropBehavior;;;
			TransformDefinition = ((str_p("CREATE"))  >> "TRANSFORM"   
								   | "TRANSFORMS"   >> "FOR"  >> SchemaResolvedUserDefinedTypeName >> +TransformGroup);;;
			TransformGroup = GroupName  >> '('  >> TransformElementList  >> ')' ;;;
			GroupName = Identifier;;;
			TransformElementList = (TransformElement >> !ch_p(',') >> TransformElement);;;
			TransformElement = ToSql  
			| FromSql;;;
			ToSql =(str_p("TO"))  >> "SQL"   >> "WITH"  >> ToSqlFunction;;;
			FromSql =(str_p("FROM"))  >> "SQL"   >> "WITH"  >> FromSqlFunction;;;
			ToSqlFunction = SpecificRoutineDesignator;;;
			FromSqlFunction = SpecificRoutineDesignator;;;
			AlterTransformStatement = ((str_p("ALTER"))  >> "TRANSFORM"   
									   | "TRANSFORMS"   >> "FOR"  >> SchemaResolvedUserDefinedTypeName >> +AlterGroup);;;
			AlterGroup = GroupName  >> '('  >> AlterTransformActionList  >> ')' ;;;
			AlterTransformActionList = ((AlterTransformAction%ch_p(',')));;;
			AlterTransformAction = AddTransformElementList  
			| DropTransformElementList;;;
			AddTransformElementList =(str_p("ADD"))  >> '('  >> TransformElementList  >> ')' ;;;
			DropTransformElementList = ((str_p("DROP"))  >> '('  >> TransformKind >> !ch_p(',') >> TransformKind >> DropBehavior  >> ')' );;;
			TransformKind =(str_p("TO"))  >> "SQL"   
			| "FROM"   >> "SQL" ;;;
			DropTransformStatement = ((str_p("DROP"))  >> "TRANSFORM"   
									  | "TRANSFORMS"  >> TransformsToBeDropped  >> "FOR"  >> SchemaResolvedUserDefinedTypeName >> DropBehavior);;;
			TransformsToBeDropped =(str_p("ALL"))  
			| TransformGroupElement;;;
			TransformGroupElement = GroupName;;;
			SequenceGeneratorDefinition = ((str_p("CREATE"))  >> "SEQUENCE"  >> SequenceGeneratorName >> !SequenceGeneratorOptions);;;
			SequenceGeneratorOptions = +SequenceGeneratorOption;;;
			SequenceGeneratorOption = SequenceGeneratorDataTypeOption  
			| CommonSequenceGeneratorOptions;;;
			CommonSequenceGeneratorOptions = +CommonSequenceGeneratorOption;;;
			CommonSequenceGeneratorOption = SequenceGeneratorStartWithOption  
			| BasicSequenceGeneratorOption;;;
			BasicSequenceGeneratorOption = SequenceGeneratorIncrementByOption  
			| SequenceGeneratorMaxvalueOption  
			| SequenceGeneratorMinvalueOption  
			| SequenceGeneratorCycleOption;;;
			SequenceGeneratorDataTypeOption =(str_p("AS")) >> DataType;;;
			SequenceGeneratorStartWithOption =(str_p("START"))  >> "WITH"  >> SequenceGeneratorStartValue;;;
			SequenceGeneratorStartValue = SignedNumericLiteral;;;
			SequenceGeneratorIncrementByOption =(str_p("INCREMENT"))  >> "BY"  >> SequenceGeneratorIncrement;;;
			SequenceGeneratorIncrement = SignedNumericLiteral;;;
			SequenceGeneratorMaxvalueOption =(str_p("MAXVALUE")) >> SequenceGeneratorMaxValue  
			| "NO"   >> "MAXVALUE" ;;;
			SequenceGeneratorMaxValue = SignedNumericLiteral;;;
			SequenceGeneratorMinvalueOption =(str_p("MINVALUE")) >> SequenceGeneratorMinValue  
			| "NO"   >> "MINVALUE" ;;;
			SequenceGeneratorMinValue = SignedNumericLiteral;;;
			SequenceGeneratorCycleOption =(str_p("CYCLE"))  
			| "NO"   >> "CYCLE" ;;;
			AlterSequenceGeneratorStatement =(str_p("ALTER"))  >> "SEQUENCE"  >> SequenceGeneratorName >> AlterSequenceGeneratorOptions;;;
			AlterSequenceGeneratorOptions = +AlterSequenceGeneratorOption;;;
			AlterSequenceGeneratorOption = AlterSequenceGeneratorRestartOption  
			| BasicSequenceGeneratorOption;;;
			AlterSequenceGeneratorRestartOption =(str_p("RESTART"))  >> "WITH"  >> SequenceGeneratorRestartValue;;;
			SequenceGeneratorRestartValue = SignedNumericLiteral;;;
			DropSequenceGeneratorStatement =(str_p("DROP"))  >> "SEQUENCE"  >> SequenceGeneratorName >> DropBehavior;;;
			GrantStatement = GrantPrivilegeStatement  
			| GrantRoleStatement;;;
			GrantPrivilegeStatement = ((str_p("GRANT")) >> Privileges  >> "TO"  >> (Grantee%ch_p(',')) >> !(str_p("WITH"))  >> "HIERARCHY"   >> "OPTION"  >> !(str_p("WITH"))  >> "GRANT"   >> "OPTION"  >> !(str_p("GRANTED"))  >> "BY"  >> Grantor);;;
			Privileges = ObjectPrivileges  >> "ON"  >> ObjectName;;;
			ObjectName = !((str_p("TABLE")) >> TableName)  
			| "DOMAIN"  >> DomainName  
			| "COLLATION"  >> CollationName  
			| "CHARACTER"   >> "SET"  >> CharacterSetName  
			| "TRANSLATION"  >> TransliterationName  
			| "TYPE"  >> SchemaResolvedUserDefinedTypeName  
			| "SEQUENCE"  >> SequenceGeneratorName  
			| SpecificRoutineDesignator;;;
			ObjectPrivileges =(str_p("ALL"))  >> "PRIVILEGES"   
			| ((Action%ch_p(',')));;;
			Action =(str_p("SELECT"))  
			| "SELECT"   >> '('  >> PrivilegeColumnList  >> ')'   
			| "SELECT"   >> '('  >> PrivilegeMethodList  >> ')'   
			| "DELETE"   
			| ((str_p("INSERT")) >> !ch_p('(') >> PrivilegeColumnList  >> ')' )  
			| ((str_p("UPDATE")) >> !ch_p('(') >> PrivilegeColumnList  >> ')' )  
			| ((str_p("REFERENCES")) >> !ch_p('(') >> PrivilegeColumnList  >> ')' )  
			| "USAGE"   
			| "TRIGGER"   
			| "UNDER"   
			| "EXECUTE" ;;;
			PrivilegeMethodList = ((SpecificRoutineDesignator%ch_p(',')));;;
			PrivilegeColumnList = ColumnNameList;;;
			Grantee =(str_p("PUBLIC"))  
			| AuthorizationIdentifier;;;
			Grantor =(str_p("CURRENT_USER"))  
			| "CURRENT_ROLE" ;;;
			RoleDefinition = ((str_p("CREATE"))  >> "ROLE"  >> RoleName >> !(str_p("WITH"))  >> "ADMIN"  >> Grantor);;;
			GrantRoleStatement = ((str_p("GRANT")) >> (RoleGranted%ch_p(','))  >> "TO"  >> (Grantee%ch_p(',')) >> !(str_p("WITH"))  >> "ADMIN"   >> "OPTION"  >> !(str_p("GRANTED"))  >> "BY"  >> Grantor);;;
			RoleGranted = RoleName;;;
			DropRoleStatement =(str_p("DROP"))  >> "ROLE"  >> RoleName;;;
			RevokeStatement = RevokePrivilegeStatement  
			| RevokeRoleStatement;;;
			RevokePrivilegeStatement = ((str_p("REVOKE")) >> !RevokeOptionExtension >> Privileges  >> "FROM"  >> (Grantee%ch_p(',')) >> !(str_p("GRANTED"))  >> "BY"  >> Grantor >> DropBehavior);;;
			RevokeOptionExtension =(str_p("GRANT"))  >> "OPTION"   >> "FOR"   
			| "HIERARCHY"   >> "OPTION"   >> "FOR" ;;;
			RevokeRoleStatement = ((str_p("REVOKE")) >> !(str_p("ADMIN"))  >> "OPTION"   >> "FOR"  >> (RoleRevoked%ch_p(','))  >> "FROM"  >> (Grantee%ch_p(',')) >> !(str_p("GRANTED"))  >> "BY"  >> Grantor >> DropBehavior);;;
			RoleRevoked = RoleName;;;
			SQLClientModuleDefinition = (ModuleNameClause >> LanguageClause >> ModuleAuthorizationClause >> !ModulePathSpecification >> !ModuleTransformGroupSpecification >> !ModuleCollation >> *TemporaryTableDeclaration >> +ModuleContents);;;
			ModuleAuthorizationClause =(str_p("SCHEMA")) >> SchemaName  
			| ((str_p("AUTHORIZATION")) >> ModuleAuthorizationIdentifier >> !((str_p("FOR"))  >> "STATIC"   >> "ONLY"   
																			  | "AND"   >> "DYNAMIC" ))  
			| ((str_p("SCHEMA")) >> SchemaName  >> "AUTHORIZATION"  >> ModuleAuthorizationIdentifier >> !((str_p("FOR"))  >> "STATIC"   >> "ONLY"   
																										  | "AND"   >> "DYNAMIC" ));;;
			ModuleAuthorizationIdentifier = AuthorizationIdentifier;;;
			ModulePathSpecification = PathSpecification;;;
			ModuleTransformGroupSpecification = TransformGroupSpecification;;;
			ModuleCollations = +ModuleCollationSpecification;;;
			ModuleCollationSpecification = ((str_p("COLLATION")) >> CollationName >> !(str_p("FOR")) >> CharacterSetSpecificationList);;;
			CharacterSetSpecificationList = ((CharacterSetSpecification%ch_p(',')));;;
			ModuleContents = DeclareCursor  
			| DynamicDeclareCursor  
			| ExternallyInvokedProcedure;;;
			ModuleNameClause = ((str_p("MODULE")) >> !SQLClientModuleName >> !ModuleCharacterSetSpecification);;;
			ModuleCharacterSetSpecification =(str_p("NAMES"))  >> "ARE"  >> CharacterSetSpecification;;;
			ExternallyInvokedProcedure =(str_p("PROCEDURE")) >> ProcedureName >> HostParameterDeclarationList  >> ';'  >> SQLProcedureStatement  >> ';' ;;;
			HostParameterDeclarationList = (ch_p('(') >> (HostParameterDeclaration%ch_p(','))  >> ')' );;;
			HostParameterDeclaration = HostParameterName >> HostParameterDataType  
			| StatusParameter;;;
			HostParameterDataType = (DataType >> !LocatorIndication);;;
			StatusParameter =(str_p("SQLSTATE"));;;
			SQLProcedureStatement = SQLExecutableStatement;;;
			SQLExecutableStatement = SQLSchemaStatement  
			| SQLDataStatement  
			| SQLControlStatement  
			| SQLTransactionStatement  
			| SQLConnectionStatement  
			| SQLSessionStatement  
			| SQLDiagnosticsStatement  
			| SQLDynamicStatement;;;
			SQLSchemaStatement = SQLSchemaDefinitionStatement  
			| SQLSchemaManipulationStatement;;;
			SQLSchemaDefinitionStatement = SchemaDefinition  
			| TableDefinition  
			| ViewDefinition  
			| SQLInvokedRoutine  
			| GrantStatement  
			| RoleDefinition  
			| DomainDefinition  
			| CharacterSetDefinition  
			| CollationDefinition  
			| TransliterationDefinition  
			| AssertionDefinition  
			| TriggerDefinition  
			| UserDefinedTypeDefinition  
			| UserDefinedCastDefinition  
			| UserDefinedOrderingDefinition  
			| TransformDefinition  
			| SequenceGeneratorDefinition;;;
			SQLSchemaManipulationStatement = DropSchemaStatement  
			| AlterTableStatement  
			| DropTableStatement  
			| DropViewStatement  
			| AlterRoutineStatement  
			| DropRoutineStatement  
			| DropUserDefinedCastStatement  
			| RevokeStatement  
			| DropRoleStatement  
			| AlterDomainStatement  
			| DropDomainStatement  
			| DropCharacterSetStatement  
			| DropCollationStatement  
			| DropTransliterationStatement  
			| DropAssertionStatement  
			| DropTriggerStatement  
			| AlterTypeStatement  
			| DropDataTypeStatement  
			| DropUserDefinedOrderingStatement  
			| AlterTransformStatement  
			| DropTransformStatement  
			| AlterSequenceGeneratorStatement  
			| DropSequenceGeneratorStatement;;;
			SQLDataStatement = OpenStatement  
			| FetchStatement  
			| CloseStatement  
			| SelectStatementSingleRow  
			| FreeLocatorStatement  
			| HoldLocatorStatement  
			| SQLDataChangeStatement;;;
			SQLDataChangeStatement = DeleteStatementPositioned  
			| DeleteStatementSearched  
			| InsertStatement  
			| UpdateStatementPositioned  
			| UpdateStatementSearched  
			| MergeStatement;;;
			SQLControlStatement = CallStatement  
			| ReturnStatement;;;
			SQLTransactionStatement = StartTransactionStatement  
			| SetTransactionStatement  
			| SetConstraintsModeStatement  
			| SavepointStatement  
			| ReleaseSavepointStatement  
			| CommitStatement  
			| RollbackStatement;;;
			SQLConnectionStatement = ConnectStatement  
			| SetConnectionStatement  
			| DisconnectStatement;;;
			SQLSessionStatement = SetSessionUserIdentifierStatement  
			| SetRoleStatement  
			| SetLocalTimeZoneStatement  
			| SetSessionCharacteristicsStatement  
			| SetCatalogStatement  
			| SetSchemaStatement  
			| SetNamesStatement  
			| SetPathStatement  
			| SetTransformGroupStatement  
			| SetSessionCollationStatement;;;
			SQLDiagnosticsStatement = GetDiagnosticsStatement;;;
			SQLDynamicStatement = SystemDescriptorStatement  
			| PrepareStatement  
			| DeallocatePreparedStatement  
			| DescribeStatement  
			| ExecuteStatement  
			| ExecuteImmediateStatement  
			| SQLDynamicDataStatement;;;
			SQLDynamicDataStatement = AllocateCursorStatement  
			| DynamicOpenStatement  
			| DynamicFetchStatement  
			| DynamicCloseStatement  
			| DynamicDeleteStatementPositioned  
			| DynamicUpdateStatementPositioned;;;
			SystemDescriptorStatement = AllocateDescriptorStatement  
			| DeallocateDescriptorStatement  
			| SetDescriptorStatement  
			| GetDescriptorStatement >> Table >> 16--Data >> type >> correspondences >> for >> C;;;
			DeclareCursor = ((str_p("DECLARE")) >> CursorName >> !CursorSensitivity >> !CursorScrollability  >> "CURSOR"  >> !CursorHoldability >> !CursorReturnability  >> "FOR"  >> CursorSpecification);;;
			CursorSensitivity =(str_p("SENSITIVE"))  
			| "INSENSITIVE"   
			| "ASENSITIVE" ;;;
			CursorScrollability =(str_p("SCROLL"))  
			| "NO"   >> "SCROLL" ;;;
			CursorHoldability =(str_p("WITH"))  >> "HOLD"   
			| "WITHOUT"   >> "HOLD" ;;;
			CursorReturnability =(str_p("WITH"))  >> "RETURN"   
			| "WITHOUT"   >> "RETURN" ;;;
			CursorSpecification = (QueryExpression >> !OrderByClause >> !UpdatabilityClause);;;
			UpdatabilityClause = ((str_p("FOR"))  >> "READ"   >> "ONLY"   
								  | ((str_p("UPDATE")) >> !(str_p("OF")) >> ColumnNameList));;;
			OrderByClause =(str_p("ORDER"))  >> "BY"  >> SortSpecificationList;;;
			OpenStatement =(str_p("OPEN")) >> CursorName;;;
			FetchStatement = ((str_p("FETCH")) >> !!(FetchOrientation  >> "FROM" ) >> CursorName  >> "INTO"  >> FetchTargetList);;;
			FetchOrientation =(str_p("NEXT"))  
			| "PRIOR"   
			| "FIRST"   
			| "LAST"   
			| ((str_p("ABSOLUTE"))  
			   | "RELATIVE"  >> SimpleValueSpecification);;;
			FetchTargetList = ((TargetSpecification%ch_p(',')) ;;;
							   
							   CloseStatement =(str_p("CLOSE")) >> CursorName;;;
							   SelectStatementSingleRow = ((str_p("SELECT")) >> !SetQuantifier >> SelectList  >> "INTO"  >> SelectTargetList >> TableExpression);;;
							   SelectTargetList = ((TargetSpecification%ch_p(',')));;;
							   DeleteStatementPositioned =(str_p("DELETE"))  >> "FROM"  >> TargetTable  >> "WHERE"   >> "CURRENT"   >> "OF"  >> CursorName;;;
							   TargetTable = TableName  
							   | "ONLY"   >> '('  >> TableName  >> ')' ;;;
							   DeleteStatementSearched = ((str_p("DELETE"))  >> "FROM"  >> TargetTable >> !(str_p("WHERE")) >> SearchCondition);;;
							   InsertStatement =(str_p("INSERT"))  >> "INTO"  >> InsertionTarget >> InsertColumnsAndSource;;;
							   InsertionTarget = TableName;;;
							   InsertColumnsAndSource = FromSubquery  
							   | FromConstructor  
							   | FromDefault;;;
							   FromSubquery = !(ch_p('(') >> InsertColumnList  >> ')'  >> !OverrideClause >> QueryExpression);;;
							   FromConstructor = !(ch_p('(') >> InsertColumnList  >> ')'  >> !OverrideClause >> ContextuallyTypedTableValueConstructor);;;
							   OverrideClause =(str_p("OVERRIDING"))  >> "USER"   >> "VALUE"   
							   | "OVERRIDING"   >> "SYSTEM"   >> "VALUE" ;;;
							   FromDefault =(str_p("DEFAULT"))  >> "VALUES" ;;;
							   InsertColumnList = ColumnNameList;;;
							   MergeStatement = ((str_p("MERGE"))  >> "INTO"  >> TargetTable >> !!((str_p("AS")) >> MergeCorrelationName)  >> "USING"  >> TableReference  >> "ON"  >> SearchCondition >> MergeOperationSpecification);;;
							   MergeCorrelationName = CorrelationName;;;
							   MergeOperationSpecification = +MergeWhenClause;;;
							   MergeWhenClause = MergeWhenMatchedClause  
							   | MergeWhenNotMatchedClause;;;
							   MergeWhenMatchedClause =(str_p("WHEN"))  >> "MATCHED"   >> "THEN"  >> MergeUpdateSpecification;;;
							   MergeWhenNotMatchedClause =(str_p("WHEN"))  >> "NOT"   >> "MATCHED"   >> "THEN"  >> MergeInsertSpecification;;;
							   MergeUpdateSpecification =(str_p("UPDATE"))  >> "SET"  >> SetClauseList;;;
							   MergeInsertSpecification = ((str_p("INSERT")) >> !ch_p('(') >> InsertColumnList  >> ')'  >> !OverrideClause  >> "VALUES"  >> MergeInsertValueList);;;
							   MergeInsertValueList = (ch_p('(') >> (MergeInsertValueElement%ch_p(','))  >> ')' );;;
							   MergeInsertValueElement = ValueExpression  
							   | ContextuallyTypedValueSpecification;;;
							   UpdateStatementPositioned =(str_p("UPDATE")) >> TargetTable  >> "SET"  >> SetClauseList  >> "WHERE"   >> "CURRENT"   >> "OF"  >> CursorName;;;
							   UpdateStatementSearched = ((str_p("UPDATE")) >> TargetTable  >> "SET"  >> SetClauseList >> !(str_p("WHERE")) >> SearchCondition);;;
							   SetClauseList = ((SetClause%ch_p(',')));;;
							   SetClause = MultipleColumnAssignment  
							   | SetTarget  >> '='  >> UpdateSource;;;
							   SetTarget = UpdateTarget  			| MutatedSetClause;;;
							   MultipleColumnAssignment = SetTargetList  >> '='  >> AssignedRow;;;
							   SetTargetList = (ch_p('(') >> (SetTarget%ch_p(','))  >> ')' );;;
							   AssignedRow = ContextuallyTypedRowValueExpression;;;
							   UpdateTarget = ObjectColumn  
							   | ObjectColumn >> LeftBracketOrTrigraph >> SimpleValueSpecification >> RightBracketOrTrigraph;;;
							   ObjectColumn = ColumnName;;;
							   MutatedSetClause = MutatedTarget  >> '.'  >> MethodName;;;
							   MutatedTarget = ObjectColumn  
							   | MutatedSetClause;;;
							   UpdateSource = ValueExpression  
							   | ContextuallyTypedValueSpecification;;;
							   TemporaryTableDeclaration = ((str_p("DECLARE"))  >> "LOCAL"   >> "TEMPORARY"   >> "TABLE"  >> TableName >> TableElementList >> !(str_p("ON"))  >> "COMMIT"  >> TableCommitAction  >> "ROWS" );;;
							   FreeLocatorStatement = ((str_p("FREE"))  >> "LOCATOR"  >> (LocatorReference%ch_p(',')));;;
							   LocatorReference = HostParameterName  
							   | EmbeddedVariableName;;;
							   HoldLocatorStatement = ((str_p("HOLD"))  >> "LOCATOR"  >> (LocatorReference%ch_p(',')));;;
							   CallStatement =(str_p("CALL")) >> RoutineInvocation;;;
							   ReturnStatement =(str_p("RETURN")) >> ReturnValue;;;
							   ReturnValue = ValueExpression  
							   | "NULL" ;;;
							   StartTransactionStatement = ((str_p("START"))  >> "TRANSACTION"  >> !((TransactionMode%ch_p(','))));;;
							   TransactionMode = IsolationLevel  
							   | TransactionAccessMode  
							   | DiagnosticsSize;;;
							   TransactionAccessMode =(str_p("READ"))  >> "ONLY"   
							   | "READ"   >> "WRITE" ;;;
							   IsolationLevel =(str_p("ISOLATION"))  >> "LEVEL"  >> LevelOfIsolation;;;
							   LevelOfIsolation =(str_p("READ"))  >> "UNCOMMITTED"   
							   | "READ"   >> "COMMITTED"   
							   | "REPEATABLE"   >> "READ"   
							   | "SERIALIZABLE" ;;;
							   DiagnosticsSize =(str_p("DIAGNOSTICS"))  >> "SIZE"  >> NumberOfConditions;;;
							   NumberOfConditions = SimpleValueSpecification;;;
							   SetTransactionStatement = ((str_p("SET")) >> !(str_p("LOCAL")) >> TransactionCharacteristics);;;
							   TransactionCharacteristics = ((str_p("TRANSACTION")) >> (TransactionMode%ch_p(',')));;;
							   SetConstraintsModeStatement = ((str_p("SET"))  >> "CONSTRAINTS"  >> ConstraintNameList  >> "DEFERRED"   
															  | "IMMEDIATE" );;;
							   ConstraintNameList =(str_p("ALL"))  
							   | ((ConstraintName%ch_p(',')));;;
							   SavepointStatement =(str_p("SAVEPOINT")) >> SavepointSpecifier;;;
							   SavepointSpecifier = SavepointName;;;
							   ReleaseSavepointStatement =(str_p("RELEASE"))  >> "SAVEPOINT"  >> SavepointSpecifier;;;
							   CommitStatement = ((str_p("COMMIT")) >> !(str_p("WORK")) >> !((str_p("AND")) >> !(str_p("NO"))  >> "CHAIN" ));;;
							   RollbackStatement = ((str_p("ROLLBACK")) >> !(str_p("WORK")) >> !((str_p("AND")) >> !(str_p("NO"))  >> "CHAIN" ) >> !SavepointClause);;;
							   SavepointClause =(str_p("TO"))  >> "SAVEPOINT"  >> SavepointSpecifier;;;
							   ConnectStatement =(str_p("CONNECT"))  >> "TO"  >> ConnectionTarget;;;
							   ConnectionTarget = (SQLServerName >> !(str_p("AS")) >> ConnectionName >> !(str_p("USER")) >> ConnectionUserName)  
							   | "DEFAULT" ;;;
							   SetConnectionStatement =(str_p("SET")) >> "CONNECTION" >> ConnectionObject;;;
							   ConnectionObject =(str_p("DEFAULT"))  
							   | ConnectionName;;;
							   DisconnectStatement =(str_p("DISCONNECT")) >> DisconnectObject;;;
							   DisconnectObject = ConnectionObject  
							   | "ALL"   
							   | "CURRENT" ;;;
							   SetSessionCharacteristicsStatement =(str_p("SET"))  >> "SESSION"   >> "CHARACTERISTICS"   >> "AS"  >> SessionCharacteristicList;;;
							   SessionCharacteristicList = ((SessionCharacteristic%ch_p(',')));;;
							   SessionCharacteristic = TransactionCharacteristics;;;
							   SetSessionUserIdentifierStatement =(str_p("SET"))  >> "SESSION"   >> "AUTHORIZATION"  >> ValueSpecification;;;
							   SetRoleStatement =(str_p("SET"))  >> "ROLE"  >> RoleSpecification;;;
							   RoleSpecification = ValueSpecification  
							   | "NONE" ;;;
							   SetLocalTimeZoneStatement =(str_p("SET"))  >> "TIME"   >> "ZONE"  >> SetTimeZoneValue;;;
							   SetTimeZoneValue = IntervalValueExpression  
							   | "LOCAL" ;;;
							   SetCatalogStatement =(str_p("SET")) >> CatalogNameCharacteristic;;;
							   CatalogNameCharacteristic =(str_p("CATALOG")) >> ValueSpecification;;;
							   SetSchemaStatement =(str_p("SET")) >> SchemaNameCharacteristic;;;
							   SchemaNameCharacteristic =(str_p("SCHEMA")) >> ValueSpecification;;;
							   SetNamesStatement =(str_p("SET")) >> CharacterSetNameCharacteristic;;;
							   CharacterSetNameCharacteristic =(str_p("NAMES")) >> ValueSpecification;;;
							   SetPathStatement =(str_p("SET")) >> SQLPathCharacteristic;;;
							   SQLPathCharacteristic =(str_p("PATH")) >> ValueSpecification;;;
							   SetTransformGroupStatement =(str_p("SET")) >> TransformGroupCharacteristic;;;
							   TransformGroupCharacteristic =(str_p("DEFAULT"))  >> "TRANSFORM"   >> "GROUP"  >> ValueSpecification  
							   | "TRANSFORM"   >> "GROUP"   >> "FOR"   >> "TYPE"  >> PathResolvedUserDefinedTypeName >> ValueSpecification;;;
							   SetSessionCollationStatement = ((str_p("SET"))  >> "COLLATION"  >> CollationSpecification >> !(str_p("FOR")) >> CharacterSetSpecificationList)  
							   | ((str_p("SET"))  >> "NO"   >> "COLLATION"  >> !(str_p("FOR")) >> CharacterSetSpecificationList);;;
							   CharacterSetSpecificationList = (CharacterSetSpecification >> !,+CharacterSetSpecification);;;
							   CollationSpecification = ValueSpecification;;;
							   AllocateDescriptorStatement = ((str_p("ALLOCATE")) >> !(str_p("SQL"))  >> "DESCRIPTOR"  >> DescriptorName >> !(str_p("WITH"))  >> "MAX"  >> Occurrences);;;
							   Occurrences = SimpleValueSpecification;;;
							   DeallocateDescriptorStatement = ((str_p("DEALLOCATE")) >> !(str_p("SQL"))  >> "DESCRIPTOR"  >> DescriptorName);;;
							   GetDescriptorStatement = ((str_p("GET")) >> !(str_p("SQL"))  >> "DESCRIPTOR"  >> DescriptorName >> GetDescriptorInformation);;;
							   GetDescriptorInformation = ((GetHeaderInformation%ch_p(',')))  
							   | ((str_p("VALUE")) >> ItemNumber >> (GetItemInformation%ch_p(',')));;;
							   GetHeaderInformation = SimpleTargetSpecification1  >> '='  >> HeaderItemName;;;
							   HeaderItemName =(str_p("COUNT"))  
							   | "KEY_TYPE"   
							   | "DYNAMIC_FUNCTION"   
							   | "DYNAMIC_FUNCTION_CODE"   
							   | "TOP_LEVEL_COUNT" ;;;
							   GetItemInformation = SimpleTargetSpecification2  >> '='  >> DescriptorItemName;;;
							   ItemNumber = SimpleValueSpecification;;;
							   SimpleTargetSpecification1 = SimpleTargetSpecification;;;
							   SimpleTargetSpecification2 = SimpleTargetSpecification;;;
							   DescriptorItemName =(str_p("CARDINALITY"))  
							   | "CHARACTER_SET_CATALOG"   
							   | "CHARACTER_SET_NAME"   
							   | "CHARACTER_SET_SCHEMA"   
							   | "COLLATION_CATALOG"   
							   | "COLLATION_NAME"   
							   | "COLLATION_SCHEMA"   
							   | "DATA"   
							   | "DATETIME_INTERVAL_CODE"   
							   | "DATETIME_INTERVAL_PRECISION"   
							   | "DEGREE"   
							   | "INDICATOR"   
							   | "KEY_MEMBER"   
							   | "LENGTH"   
							   | "LEVEL"   
							   | "NAME"   
							   | "NULLABLE"   
							   | "OCTET_LENGTH"   
							   | "PARAMETER_MODE"   
							   | "PARAMETER_ORDINAL_POSITION"   
							   | "PARAMETER_SPECIFIC_CATALOG"   
							   | "PARAMETER_SPECIFIC_NAME"   
							   | "PARAMETER_SPECIFIC_SCHEMA"   
							   | "PRECISION"   
							   | "RETURNED_CARDINALITY"   
							   | "RETURNED_LENGTH"   
							   | "RETURNED_OCTET_LENGTH"   
							   | "SCALE"   
							   | "SCOPE_CATALOG"   
							   | "SCOPE_NAME"   
							   | "SCOPE_SCHEMA"   
							   | "TYPE"   
							   | "UNNAMED"   
							   | "USER_DEFINED_TYPE_CATALOG"   
							   | "USER_DEFINED_TYPE_NAME"   
							   | "USER_DEFINED_TYPE_SCHEMA"   
							   | "USER_DEFINED_TYPE_CODE" ;;;
							   SetDescriptorStatement = ((str_p("SET")) >> !(str_p("SQL"))  >> "DESCRIPTOR"  >> DescriptorName >> SetDescriptorInformation);;;
							   SetDescriptorInformation = ((SetHeaderInformation%ch_p(',')))  
							   | ((str_p("VALUE")) >> ItemNumber >> (SetItemInformation%ch_p(',')));;;
							   SetHeaderInformation = HeaderItemName  >> '='  >> SimpleValueSpecification1;;;
							   SetItemInformation = DescriptorItemName  >> '='  >> SimpleValueSpecification2;;;
							   SimpleValueSpecification1 = SimpleValueSpecification;;;
							   SimpleValueSpecification2 = SimpleValueSpecification;;;
							   ItemNumber = SimpleValueSpecification;;;
							   PrepareStatement = ((str_p("PREPARE")) >> SQLStatementName >> !AttributesSpecification  >> "FROM"  >> SQLStatementVariable);;;
							   AttributesSpecification =(str_p("ATTRIBUTES")) >> AttributesVariable;;;
							   AttributesVariable = SimpleValueSpecification;;;
							   SQLStatementVariable = SimpleValueSpecification;;;
							   PreparableStatement = PreparableSQLDataStatement  
							   | PreparableSQLSchemaStatement  
							   | PreparableSQLTransactionStatement  
							   | PreparableSQLControlStatement  
							   | PreparableSQLSessionStatement  
							   | PreparableImplementationDefinedStatement;;;
							   PreparableSQLDataStatement = DeleteStatementSearched  
							   | DynamicSingleRowSelectStatement  
							   | InsertStatement  
							   | DynamicSelectStatement  
							   | UpdateStatementSearched  
							   | MergeStatement  
							   | PreparableDynamicDeleteStatementPositioned  
							   | PreparableDynamicUpdateStatementPositioned;;;
							   PreparableSQLSchemaStatement = SQLSchemaStatement;;;
							   PreparableSQLTransactionStatement = SQLTransactionStatement;;;
							   PreparableSQLControlStatement = SQLControlStatement;;;
							   PreparableSQLSessionStatement = SQLSessionStatement;;;
							   DynamicSelectStatement = CursorSpecification;;;
							   PreparableImplementationDefinedStatement = nothing_p;;;
							   CursorAttributes = +CursorAttribute;;;
							   CursorAttribute = CursorSensitivity  
							   | CursorScrollability  
							   | CursorHoldability  
							   | CursorReturnability;;;
							   DeallocatePreparedStatement =(str_p("DEALLOCATE"))  >> "PREPARE"  >> SQLStatementName;;;
							   DescribeStatement = DescribeInputStatement  
							   | DescribeOutputStatement;;;
							   DescribeInputStatement = ((str_p("DESCRIBE"))  >> "INPUT"  >> SQLStatementName >> UsingDescriptor >> !NestingOption);;;
							   DescribeOutputStatement = ((str_p("DESCRIBE")) >> !(str_p("OUTPUT")) >> DescribedObject >> UsingDescriptor >> !NestingOption);;;
							   NestingOption =(str_p("WITH"))  >> "NESTING"   
							   | "WITHOUT"   >> "NESTING" ;;;
							   UsingDescriptor = ((str_p("USING")) >> !(str_p("SQL"))  >> "DESCRIPTOR"  >> DescriptorName);;;
							   DescribedObject = SQLStatementName  
							   | "CURSOR"  >> ExtendedCursorName  >> "STRUCTURE" ;;;
							   InputUsingClause = UsingArguments  
							   | UsingInputDescriptor;;;
							   UsingArguments = ((str_p("USING")) >> (UsingArgument%ch_p(',')));;;
							   UsingArgument = GeneralValueSpecification;;;
							   UsingInputDescriptor = UsingDescriptor;;;
							   OutputUsingClause = IntoArguments  
							   | IntoDescriptor;;;
							   IntoArguments = ((str_p("INTO")) >> (IntoArgument%ch_p(',')));;;
							   IntoArgument = TargetSpecification;;;
							   IntoDescriptor = ((str_p("INTO")) >> !(str_p("SQL"))  >> "DESCRIPTOR"  >> DescriptorName);;;
							   ExecuteStatement = ((str_p("EXECUTE")) >> SQLStatementName >> !ResultUsingClause >> !ParameterUsingClause);;;
							   ResultUsingClause = OutputUsingClause;;;
							   ParameterUsingClause = InputUsingClause;;;
							   ExecuteImmediateStatement =(str_p("EXECUTE"))  >> "IMMEDIATE"  >> SQLStatementVariable;;;
							   DynamicDeclareCursor = ((str_p("DECLARE")) >> CursorName >> !CursorSensitivity >> !CursorScrollability  >> "CURSOR"  >> !CursorHoldability >> !CursorReturnability  >> "FOR"  >> StatementName);;;
							   AllocateCursorStatement =(str_p("ALLOCATE")) >> ExtendedCursorName >> CursorIntent;;;
							   CursorIntent = StatementCursor  
							   | ResultSetCursor;;;
							   StatementCursor = !(CursorSensitivity >> !CursorScrollability  >> "CURSOR"  >> !CursorHoldability >> !CursorReturnability  >> "FOR"  >> ExtendedStatementName);;;
							   ResultSetCursor =(str_p("FOR"))  >> "PROCEDURE"  >> SpecificRoutineDesignator;;;
							   DynamicOpenStatement = ((str_p("OPEN")) >> DynamicCursorName >> !InputUsingClause);;;
							   DynamicFetchStatement = ((str_p("FETCH")) >> !!(FetchOrientation  >> "FROM" ) >> DynamicCursorName >> OutputUsingClause);;;
							   DynamicSingleRowSelectStatement = QuerySpecification;;;
							   DynamicCloseStatement =(str_p("CLOSE")) >> DynamicCursorName;;;
							   DynamicDeleteStatementPositioned =(str_p("DELETE"))  >> "FROM"  >> TargetTable  >> "WHERE"   >> "CURRENT"   >> "OF"  >> DynamicCursorName;;;
							   DynamicUpdateStatementPositioned =(str_p("UPDATE")) >> TargetTable  >> "SET"  >> SetClauseList  >> "WHERE"   >> "CURRENT"   >> "OF"  >> DynamicCursorName;;;
							   PreparableDynamicDeleteStatementPositioned = ((str_p("DELETE")) >> !(str_p("FROM")) >> TargetTable  >> "WHERE"   >> "CURRENT"   >> "OF"  >> !ScopeOption >> CursorName);;;
							   PreparableDynamicUpdateStatementPositioned = ((str_p("UPDATE")) >> !TargetTable  >> "SET"  >> SetClauseList  >> "WHERE"   >> "CURRENT"   >> "OF"  >> !ScopeOption >> CursorName);;;
							   EmbeddedSQLHostProgram = EmbeddedSQLAdaProgram  
							   | EmbeddedSQLCProgram  
							   | EmbeddedSQLCOBOLProgram  
							   | EmbeddedSQLFortranProgram  
							   | EmbeddedSQLMUMPSProgram  
							   | EmbeddedSQLPascalProgram  
							   | EmbeddedSQLPLIProgram;;;
							   EmbeddedSQLStatement = (SQLPrefix >> StatementOrDeclaration >> !SQLTerminator);;;
							   StatementOrDeclaration = DeclareCursor  
							   | DynamicDeclareCursor  
							   | TemporaryTableDeclaration  
							   | EmbeddedAuthorizationDeclaration  
							   | EmbeddedPathSpecification  
							   | EmbeddedTransformGroupSpecification  
							   | EmbeddedCollationSpecification  
							   | EmbeddedExceptionDeclaration  
							   | HandlerDeclaration  
							   | SQLProcedureStatement;;;
							   SQLPrefix =(str_p("EXEC"))  >> "SQL"   
							   | '&'   >> "SQL"   >> '(' ;;;
							   SQLTerminator = ENDEXEC  
							   | ';'   
							   | ')' ;;;
							   EmbeddedAuthorizationDeclaration =(str_p("DECLARE")) >> EmbeddedAuthorizationClause;;;
							   EmbeddedAuthorizationClause =(str_p("SCHEMA")) >> SchemaName  
							   | ((str_p("AUTHORIZATION")) >> EmbeddedAuthorizationIdentifier >> !((str_p("FOR"))  >> "STATIC"   >> "ONLY"   
																								   | "AND"   >> "DYNAMIC" ))  
							   | ((str_p("SCHEMA")) >> SchemaName  >> "AUTHORIZATION"  >> EmbeddedAuthorizationIdentifier >> !((str_p("FOR"))  >> "STATIC"   >> "ONLY"   
																															   | "AND"   >> "DYNAMIC" ));;;
							   EmbeddedAuthorizationIdentifier = ModuleAuthorizationIdentifier;;;
							   EmbeddedPathSpecification = PathSpecification;;;
							   EmbeddedTransformGroupSpecification = TransformGroupSpecification;;;
							   EmbeddedCollationSpecification = ModuleCollations;;;
							   EmbeddedSQLDeclareSection = (EmbeddedSQLBeginDeclare >> !EmbeddedCharacterSetDeclaration >> *HostVariableDefinition >> EmbeddedSQLEndDeclare)  
							   | EmbeddedSQLMUMPSDeclare;;;
							   EmbeddedCharacterSetDeclaration =(str_p("SQL"))  >> "NAMES"   >> "ARE"  >> CharacterSetSpecification;;;
							   EmbeddedSQLBeginDeclare = (SQLPrefix  >> "BEGIN"   >> "DECLARE"   >> "SECTION"  >> !SQLTerminator);;;
							   EmbeddedSQLEndDeclare = (SQLPrefix  >> "END"   >> "DECLARE"   >> "SECTION"  >> !SQLTerminator);;;
							   EmbeddedSQLMUMPSDeclare = (SQLPrefix  >> "BEGIN"   >> "DECLARE"   >> "SECTION"  >> !EmbeddedCharacterSetDeclaration >> +HostVariableDefinition)  >> "END"   >> "DECLARE"   >> "SECTION"  >> SQLTerminator);;;
			HostVariableDefinition = AdaVariableDefinition  
			| CVariableDefinition  
			| COBOLVariableDefinition  
			| FortranVariableDefinition  
			| MUMPSVariableDefinition  
			| PascalVariableDefinition  
			| PLIVariableDefinition;;;
			EmbeddedVariableName = ch_p(':') >> HostIdentifier;;;
			HostIdentifier = AdaHostIdentifier  
			| CHostIdentifier  
			| COBOLHostIdentifier  
			| FortranHostIdentifier  
			| MUMPSHostIdentifier  
			| PascalHostIdentifier  
			| PLIHostIdentifier;;;
			EmbeddedExceptionDeclaration =(str_p("WHENEVER")) >> Condition >> ConditionAction;;;
			Condition = SQLCondition;;;
			SQLCondition = MajorCategory  
			| ((str_p("SQLSTATE")) >> (SQLSTATEClassValue >> !,SQLSTATESubclassValue))  
			| "CONSTRAINT"  >> ConstraintName;;;
			MajorCategory =(str_p("SQLEXCEPTION"))  
			| "SQLWARNING"   
			| "NOT"   >> "FOUND" ;;;
			SQLSTATEClassValue = SQLSTATEChar >> SQLSTATECharnothing_p;;;
			SQLSTATESubclassValue = SQLSTATEChar >> SQLSTATEChar >> SQLSTATECharfail_p;;;
			SQLSTATEChar = upper_p  
			| digit_p;;;
			ConditionAction =(str_p("CONTINUE"))  
			| GoTo;;;
			GoTo = ((str_p("GOTO"))  
					| "GO"   >> "TO"  >> GotoTarget);;;
			GotoTarget = HostLabelIdentifier  
			| uint_p  
			| HostPLILabelVariable;;;
			HostLabelIdentifier = nothing_p;;;
			HostPLILabelVariable = nothing_p;;;
			EmbeddedSQLAdaProgram = nothing_p;;;
			AdaVariableDefinition = ((AdaHostIdentifier%ch_p(','))  >> ':'  >> AdaTypeSpecification >> !AdaInitialValue);;;
			AdaInitialValue = (AdaAssignmentOperator >> +CharacterRepresentation);;;
			AdaAssignmentOperator = ch_p(':')  >> '=' ;;;
			AdaHostIdentifier = nothing_p;;;
			AdaTypeSpecification = AdaQualifiedTypeSpecification  
			| AdaUnqualifiedTypeSpecification  
			| AdaDerivedTypeSpecification;;;
			AdaQualifiedTypeSpecification = Interfaces.((str_p("SQL"))  >> '.'   >> "CHAR"  >> !((str_p("CHARACTER"))  >> "SET"  >> !(str_p("IS")) >> CharacterSetSpecification)  >> '('  >> 1 >> DoublePeriod >> Length  >> ')' )  
			| InterfacesSQL  >> '.'   >> "SMALLINT"   
			| Interfaces.(str_p("SQL"))  >> '.'   >> "INT"   
			| InterfacesSQL  >> '.'   >> "BIGINT"   
			| Interfaces.(str_p("SQL"))  >> '.'   >> "REAL"   
			| InterfacesSQL  >> '.'  >> "DOUBLE_PRECISION"  
			| Interfaces.(str_p("SQL"))  >> '.'   >> "BOOLEAN"   
			| InterfacesSQL  >> '.'  >> "SQLSTATE_TYPE"  
			| Interfaces.(str_p("SQL"))  >> '.'  >> "INDICATOR_TYPE";;;
			AdaUnqualifiedTypeSpecification =(str_p("CHAR"))  >> '('  >> 1 >> DoublePeriod >> Length  >> ')'   
			| "SMALLINT"   
			| "INT"   
			| "BIGINT"   
			| "REAL"   
			| "DOUBLE_PRECISION"  
			| "BOOLEAN"   
			| "SQLSTATE_TYPE"  
			| "INDICATOR_TYPE";;;
			AdaDerivedTypeSpecification = AdaCLOBVariable  
			| AdaCLOBLocatorVariable  
			| AdaBLOBVariable  
			| AdaBLOBLocatorVariable  
			| AdaUserDefinedTypeVariable  
			| AdaUserDefinedTypeLocatorVariable  
			| AdaREFVariable  
			| AdaArrayLocatorVariable  
			| AdaMultisetLocatorVariable;;;
			AdaCLOBVariable = ((str_p("SQL"))  >> "TYPE"   >> "IS"   >> "CLOB"   >> '('  >> LargeObjectLength  >> ')'  >> !((str_p("CHARACTER"))  >> "SET"  >> !(str_p("IS")) >> CharacterSetSpecification));;;
			AdaCLOBLocatorVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"   >> "CLOB"   >> "AS"   >> "LOCATOR" ;;;
			AdaBLOBVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"   >> "BLOB"   >> '('  >> LargeObjectLength  >> ')' ;;;
			AdaBLOBLocatorVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"   >> "BLOB"   >> "AS"   >> "LOCATOR" ;;;
			AdaUserDefinedTypeVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"  >> PathResolvedUserDefinedTypeName  >> "AS"  >> PredefinedType;;;
			AdaUserDefinedTypeLocatorVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"  >> PathResolvedUserDefinedTypeName  >> "AS"   >> "LOCATOR" ;;;
			AdaREFVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"  >> ReferenceType;;;
			AdaArrayLocatorVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"  >> ArrayType  >> "AS"   >> "LOCATOR" ;;;
			AdaMultisetLocatorVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"  >> MultisetType  >> "AS"   >> "LOCATOR" ;;;
			EmbeddedSQLCProgram = nothing_p;;;
			CVariableDefinition = !(CStorageClass >> !CClassModifier >> CVariableSpecification  >> ';' );;;
			CVariableSpecification = CNumericVariable  
			| CCharacterVariable  
			| CDerivedVariable;;;
			CStorageClass = Auto  
			| Extern  
			| Static;;;
			CClassModifier = str_p("const" )
			| "volatile" ;;;
			CNumericVariable = ("Long" >> "Long"  
								| "Long"  
								| Short  
								| Float  
								| Double >> CHostIdentifier >> !CInitialValue >> *((ch_p(',') >> CHostIdentifier >> !CInitialValue)));;;
			CCharacterVariable = (CCharacterType >> !((str_p("CHARACTER"))  >> "SET"  >> !(str_p("IS")) >> CharacterSetSpecification) >> CHostIdentifier >> CArraySpecification >> !CInitialValue >> *((ch_p(',') >> CHostIdentifier >> CArraySpecification >> !CInitialValue)));;;
			CCharacterType = Char  
			| Unsigned >> Char  
			| Unsigned >> Short;;;
			CArraySpecification = ch_p('{') >> Length  >> '}' ;;;
			CHostIdentifier = nothing_p;;;
			CDerivedVariable = CVARCHARVariable  
			| CNCHARVariable  
			| CNCHARVARYINGVariable  
			| CCLOBVariable  
			| CNCLOBVariable  
			| CBLOBVariable  
			| CUserDefinedTypeVariable  
			| CCLOBLocatorVariable  
			| CBLOBLocatorVariable  
			| CArrayLocatorVariable  
			| CMultisetLocatorVariable  
			| CUserDefinedTypeLocatorVariable  
			| CREFVariable;;;
			CVARCHARVariable = ((str_p("VARCHAR")) >> !((str_p("CHARACTER"))  >> "SET"  >> !(str_p("IS")) >> CharacterSetSpecification) >> CHostIdentifier >> CArraySpecification >> !CInitialValue >> *((ch_p(',') >> CHostIdentifier >> CArraySpecification >> !CInitialValue)));;;
			CNCHARVariable = ((str_p("NCHAR")) >> !((str_p("CHARACTER"))  >> "SET"  >> !(str_p("IS")) >> CharacterSetSpecification) >> CHostIdentifier >> CArraySpecification >> !CInitialValue >> *((ch_p(',') >> CHostIdentifier >> CArraySpecification >> !CInitialValue)));;;
			CNCHARVARYINGVariable = ((str_p("NCHAR"))  >> "VARYING"  >> !((str_p("CHARACTER"))  >> "SET"  >> !(str_p("IS")) >> CharacterSetSpecification) >> CHostIdentifier >> CArraySpecification >> !CInitialValue >> *((ch_p(',') >> CHostIdentifier >> CArraySpecification >> !CInitialValue)));;;
			CCLOBVariable = ((str_p("SQL"))  >> "TYPE"   >> "IS"   >> "CLOB"   >> '('  >> LargeObjectLength  >> ')'  >> !((str_p("CHARACTER"))  >> "SET"  >> !(str_p("IS")) >> CharacterSetSpecification) >> CHostIdentifier >> !CInitialValue >> *((ch_p(',') >> CHostIdentifier >> !CInitialValue)));;;
			CNCLOBVariable = ((str_p("SQL"))  >> "TYPE"   >> "IS"   >> "NCLOB"   >> '('  >> LargeObjectLength  >> ')'  >> !((str_p("CHARACTER"))  >> "SET"  >> !(str_p("IS")) >> CharacterSetSpecification) >> CHostIdentifier >> !CInitialValue >> *((ch_p(',') >> CHostIdentifier >> !CInitialValue)));;;
			CUserDefinedTypeVariable = ((str_p("SQL"))  >> "TYPE"   >> "IS"  >> PathResolvedUserDefinedTypeName  >> "AS"  >> PredefinedType >> CHostIdentifier >> !CInitialValue >> *((ch_p(',') >> CHostIdentifier >> !CInitialValue)));;;
			CBLOBVariable = ((str_p("SQL"))  >> "TYPE"   >> "IS"   >> "BLOB"   >> '('  >> LargeObjectLength  >> ')'  >> CHostIdentifier >> !CInitialValue >> *((ch_p(',') >> CHostIdentifier >> !CInitialValue)));;;
			CCLOBLocatorVariable = ((str_p("SQL"))  >> "TYPE"   >> "IS"   >> "CLOB"   >> "AS"   >> "LOCATOR"  >> CHostIdentifier >> !CInitialValue >> *((ch_p(',') >> CHostIdentifier >> !CInitialValue)));;;
			CBLOBLocatorVariable = ((str_p("SQL"))  >> "TYPE"   >> "IS"   >> "BLOB"   >> "AS"   >> "LOCATOR"  >> CHostIdentifier >> !CInitialValue >> *((ch_p(',') >> CHostIdentifier >> !CInitialValue)));;;
			CArrayLocatorVariable = ((str_p("SQL"))  >> "TYPE"   >> "IS"  >> ArrayType  >> "AS"   >> "LOCATOR"  >> CHostIdentifier >> !CInitialValue >> *((ch_p(',') >> CHostIdentifier >> !CInitialValue)));;;
			CMultisetLocatorVariable = ((str_p("SQL"))  >> "TYPE"   >> "IS"  >> MultisetType  >> "AS"   >> "LOCATOR"  >> CHostIdentifier >> !CInitialValue >> *((ch_p(',') >> CHostIdentifier >> !CInitialValue)));;;
			CUserDefinedTypeLocatorVariable = ((str_p("SQL"))  >> "TYPE"   >> "IS"  >> PathResolvedUserDefinedTypeName  >> "AS"   >> "LOCATOR"  >> CHostIdentifier >> !CInitialValue >> *((ch_p(',') >> CHostIdentifier >> !CInitialValue)));;;
			CREFVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"  >> ReferenceType;;;
			CInitialValue = (ch_p('=') >> +CharacterRepresentation);;;
			EmbeddedSQLCOBOLProgram = nothing_p;;;
			COBOLVariableDefinition = (01  
									   | 77 >> COBOLHostIdentifier >> COBOLTypeSpecification >> *CharacterRepresentation  >> '.' );;;
			COBOLHostIdentifier = nothing_p;;;
			COBOLTypeSpecification = COBOLCharacterType  
			| COBOLNationalCharacterType  
			| COBOLNumericType  
			| COBOLIntegerType  
			| COBOLDerivedTypeSpecification;;;
			COBOLDerivedTypeSpecification = COBOLCLOBVariable  
			| COBOLNCLOBVariable  
			| COBOLBLOBVariable  
			| COBOLUserDefinedTypeVariable  
			| COBOLCLOBLocatorVariable  
			| COBOLBLOBLocatorVariable  
			| COBOLArrayLocatorVariable  
			| COBOLMultisetLocatorVariable  
			| COBOLUserDefinedTypeLocatorVariable  
			| COBOLREFVariable;;;
			COBOLCharacterType = !(((str_p("CHARACTER"))  >> "SET"  >> !(str_p("IS")) >> CharacterSetSpecification) >> "PIC"  
								   | "PICTURE" >> !(str_p("IS")) >> +(X >> !ch_p('(') >> Length  >> ')' ));;;
			COBOLNationalCharacterType = !(((str_p("CHARACTER"))  >> "SET"  >> !(str_p("IS")) >> CharacterSetSpecification) >> "PIC"  
										   | "PICTURE" >> !(str_p("IS")) >> +(N >> !ch_p('(') >> Length  >> ')' ));;;
			COBOLCLOBVariable = !(((str_p("USAGE")) >> !(str_p("IS")))  >> "SQL"   >> "TYPE"   >> "IS"   >> "CLOB"   >> '('  >> LargeObjectLength  >> ')'  >> !((str_p("CHARACTER"))  >> "SET"  >> !(str_p("IS")) >> CharacterSetSpecification));;;
			COBOLNCLOBVariable = !(((str_p("USAGE")) >> !(str_p("IS")))  >> "SQL"   >> "TYPE"   >> "IS"   >> "NCLOB"   >> '('  >> LargeObjectLength  >> ')'  >> !((str_p("CHARACTER"))  >> "SET"  >> !(str_p("IS")) >> CharacterSetSpecification));;;
			COBOLBLOBVariable = !(((str_p("USAGE")) >> !(str_p("IS")))  >> "SQL"   >> "TYPE"   >> "IS"   >> "BLOB"   >> '('  >> LargeObjectLength  >> ')' );;;
			COBOLUserDefinedTypeVariable = !(((str_p("USAGE")) >> !(str_p("IS")))  >> "SQL"   >> "TYPE"   >> "IS"  >> PathResolvedUserDefinedTypeName  >> "AS"  >> PredefinedType);;;
			COBOLCLOBLocatorVariable = !(((str_p("USAGE")) >> !(str_p("IS")))  >> "SQL"   >> "TYPE"   >> "IS"   >> "CLOB"   >> "AS"   >> "LOCATOR" );;;
			COBOLBLOBLocatorVariable = !(((str_p("USAGE")) >> !(str_p("IS")))  >> "SQL"   >> "TYPE"   >> "IS"   >> "BLOB"   >> "AS"   >> "LOCATOR" );;;
			COBOLArrayLocatorVariable = !(((str_p("USAGE")) >> !(str_p("IS")))  >> "SQL"   >> "TYPE"   >> "IS"  >> ArrayType  >> "AS"   >> "LOCATOR" );;;
			COBOLMultisetLocatorVariable = !(((str_p("USAGE")) >> !(str_p("IS")))  >> "SQL"   >> "TYPE"   >> "IS"  >> MultisetType  >> "AS"   >> "LOCATOR" );;;
			COBOLUserDefinedTypeLocatorVariable = !(((str_p("USAGE")) >> !(str_p("IS")))  >> "SQL"   >> "TYPE"   >> "IS"  >> PathResolvedUserDefinedTypeName  >> "AS"   >> "LOCATOR" );;;
			COBOLREFVariable = !(((str_p("USAGE")) >> !(str_p("IS")))  >> "SQL"   >> "TYPE"   >> "IS"  >> ReferenceType);;;
			COBOLNumericType = (
								"PIC"  
								| "PICTURE" >> !(str_p("IS")) >> "S" >> COBOLNinesSpecification >> !((str_p("USAGE")) >> !(str_p("IS"))) >> "DISPLAY" >> "SIGN"  >> "LEADING"  >> "SEPARATE");;;
			COBOLNinesSpecification = (COBOLNines >> !("V" >> !COBOLNines))  
			| "V" >> COBOLNines;;;
			COBOLIntegerType = COBOLBinaryInteger;;;
			COBOLBinaryInteger = ("PIC"  
								  | "PICTURE" >> !(str_p("IS")) >> "S" >> COBOLNines >> !((str_p("USAGE")) >> !(str_p("IS")))  >> "BINARY" );;;
			COBOLNines = +((9 >> !ch_p('(') >> Length  >> ')' ));;;
			EmbeddedSQLFortranProgram = nothing_p;;;
			FortranVariableDefinition = (FortranTypeSpecification >> (FortranHostIdentifier%ch_p(',')));;;
			FortranHostIdentifier = nothing_p;;;
			FortranTypeSpecification = ((str_p("CHARACTER")) >> !ch_p('*') >> Length >> !((str_p("CHARACTER"))  >> "SET"  >> !(str_p("IS")) >> CharacterSetSpecification))  
			| "CHARACTER"  >> KIND=(n >> !ch_p('*') >> Length >> !((str_p("CHARACTER"))  >> "SET"  >> !(str_p("IS")) >> CharacterSetSpecification))  
			| "INTEGER"   
			| "REAL"   
			| "DOUBLE"   >> "PRECISION"   
			| "LOGICAL"
			| FortranDerivedTypeSpecification;;;
			FortranDerivedTypeSpecification = FortranCLOBVariable  
			| FortranBLOBVariable  
			| FortranUserDefinedTypeVariable  
			| FortranCLOBLocatorVariable  
			| FortranBLOBLocatorVariable  
			| FortranUserDefinedTypeLocatorVariable  
			| FortranArrayLocatorVariable  
			| FortranMultisetLocatorVariable  
			| FortranREFVariable;;;
			FortranCLOBVariable = ((str_p("SQL"))  >> "TYPE"   >> "IS"   >> "CLOB"   >> '('  >> LargeObjectLength  >> ')'  >> !((str_p("CHARACTER"))  >> "SET"  >> !(str_p("IS")) >> CharacterSetSpecification));;;
			FortranBLOBVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"   >> "BLOB"   >> '('  >> LargeObjectLength  >> ')' ;;;
			FortranUserDefinedTypeVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"  >> PathResolvedUserDefinedTypeName  >> "AS"  >> PredefinedType;;;
			FortranCLOBLocatorVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"   >> "CLOB"   >> "AS"   >> "LOCATOR" ;;;
			FortranBLOBLocatorVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"   >> "BLOB"   >> "AS"   >> "LOCATOR" ;;;
			FortranUserDefinedTypeLocatorVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"  >> PathResolvedUserDefinedTypeName  >> "AS"   >> "LOCATOR" ;;;
			FortranArrayLocatorVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"  >> ArrayType  >> "AS"   >> "LOCATOR" ;;;
			FortranMultisetLocatorVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"  >> MultisetType  >> "AS"   >> "LOCATOR" ;;;
			FortranREFVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"  >> ReferenceType;;;
			EmbeddedSQLMUMPSProgram = nothing_p;;;
			MUMPSVariableDefinition = MUMPSNumericVariable  >> ';'   
			| MUMPSCharacterVariable  >> ';'   
			| MUMPSDerivedTypeSpecification  >> ';' ;;;
			MUMPSCharacterVariable = ((str_p("VARCHAR")) >> MUMPSHostIdentifier >> MUMPSLengthSpecification >> *(ch_p(',') >> MUMPSHostIdentifier >> MUMPSLengthSpecification));;;
			MUMPSHostIdentifier = nothing_p;;;
			MUMPSLengthSpecification = ch_p('(') >> Length  >> ')' ;;;
			MUMPSNumericVariable = (MUMPSTypeSpecification >> (MUMPSHostIdentifier%ch_p(',')));;;
			MUMPSTypeSpecification =(str_p("INT"))  
			| ((str_p("DEC")) >> !(ch_p('(') >> Precision >> !ch_p(',') >> Scale  >> ')' ))  
			| "REAL" ;;;
			MUMPSDerivedTypeSpecification = MUMPSCLOBVariable  
			| MUMPSBLOBVariable  
			| MUMPSUserDefinedTypeVariable  
			| MUMPSCLOBLocatorVariable  
			| MUMPSBLOBLocatorVariable  
			| MUMPSUserDefinedTypeLocatorVariable  
			| MUMPSArrayLocatorVariable  
			| MUMPSMultisetLocatorVariable  
			| MUMPSREFVariable;;;
			MUMPSCLOBVariable = ((str_p("SQL"))  >> "TYPE"   >> "IS"   >> "CLOB"   >> '('  >> LargeObjectLength  >> ')'  >> !((str_p("CHARACTER"))  >> "SET"  >> !(str_p("IS")) >> CharacterSetSpecification));;;
			MUMPSBLOBVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"   >> "BLOB"   >> '('  >> LargeObjectLength  >> ')' ;;;
			MUMPSUserDefinedTypeVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"  >> PathResolvedUserDefinedTypeName  >> "AS"  >> PredefinedType;;;
			MUMPSCLOBLocatorVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"   >> "CLOB"   >> "AS"   >> "LOCATOR" ;;;
			MUMPSBLOBLocatorVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"   >> "BLOB"   >> "AS"   >> "LOCATOR" ;;;
			MUMPSUserDefinedTypeLocatorVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"  >> PathResolvedUserDefinedTypeName  >> "AS"   >> "LOCATOR" ;;;
			MUMPSArrayLocatorVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"  >> ArrayType  >> "AS"   >> "LOCATOR" ;;;
			MUMPSMultisetLocatorVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"  >> MultisetType  >> "AS"   >> "LOCATOR" ;;;
			MUMPSREFVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"  >> ReferenceType;;;
			EmbeddedSQLPascalProgram = nothing_p;;;
			PascalVariableDefinition = ((PascalHostIdentifier%ch_p(','))  >> ':'  >> PascalTypeSpecification  >> ';' );;;
			PascalHostIdentifier = nothing_p;;;
			PascalTypeSpecification = (str_p(PACKED)  >> "ARRAY"   >> '{'  >> 1 >> DoublePeriod >> Length  >> '}'   >> "OF"   >> "CHAR"  >> !((str_p("CHARACTER"))  >> "SET"  >> !(str_p("IS")) >> CharacterSetSpecification))  
			| "INTEGER"   
			| "REAL"   
			| ((str_p("CHAR")) >> !((str_p("CHARACTER"))  >> "SET"  >> !(str_p("IS")) >> CharacterSetSpecification))  
			| "BOOLEAN"   
			| PascalDerivedTypeSpecification;;;
			PascalDerivedTypeSpecification = PascalCLOBVariable  
			| PascalBLOBVariable  
			| PascalUserDefinedTypeVariable  
			| PascalCLOBLocatorVariable  
			| PascalBLOBLocatorVariable  
			| PascalUserDefinedTypeLocatorVariable  
			| PascalArrayLocatorVariable  
			| PascalMultisetLocatorVariable  
			| PascalREFVariable;;;
			PascalCLOBVariable = ((str_p("SQL"))  >> "TYPE"   >> "IS"   >> "CLOB"   >> '('  >> LargeObjectLength  >> ')'  >> !((str_p("CHARACTER"))  >> "SET"  >> !(str_p("IS")) >> CharacterSetSpecification));;;
			PascalBLOBVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"   >> "BLOB"   >> '('  >> LargeObjectLength  >> ')' ;;;
			PascalCLOBLocatorVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"   >> "CLOB"   >> "AS"   >> "LOCATOR" ;;;
			PascalUserDefinedTypeVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"  >> PathResolvedUserDefinedTypeName  >> "AS"  >> PredefinedType;;;
			PascalBLOBLocatorVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"   >> "BLOB"   >> "AS"   >> "LOCATOR" ;;;
			PascalUserDefinedTypeLocatorVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"  >> PathResolvedUserDefinedTypeName  >> "AS"   >> "LOCATOR" ;;;
			PascalArrayLocatorVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"  >> ArrayType  >> "AS"   >> "LOCATOR" ;;;
			PascalMultisetLocatorVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"  >> MultisetType  >> "AS"   >> "LOCATOR" ;;;
			PascalREFVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"  >> ReferenceType;;;
			EmbeddedSQLPLIProgram = nothing_p;;;
			PLIVariableDefinition = (str_p("DCL")  
									 | "DECLARE"  >> PLIHostIdentifier  
									 | (ch_p('(') >> (PLIHostIdentifier%ch_p(','))  >> ')' ) >> PLITypeSpecification >> *CharacterRepresentation  >> ';' );;;
			PLIHostIdentifier = nothing_p;;;
			PLITypeSpecification = ((str_p("CHAR"))  
									| "CHARACTER"  >> !(str_p("VARYING"))  >> '('  >> Length  >> ')'  >> !((str_p("CHARACTER"))  >> "SET"  >> !(str_p("IS")) >> CharacterSetSpecification))  
			| (PLITypeFixedDecimal  >> '('  >> Precision >> !ch_p(',') >> Scale  >> ')' )  
			| (PLITypeFixedBinary >> !ch_p('(') >> Precision  >> ')' )  
			| PLITypeFloatBinary  >> '('  >> Precision  >> ')'   
			| PLIDerivedTypeSpecification;;;
			PLIDerivedTypeSpecification = PLICLOBVariable  
			| PLIBLOBVariable  
			| PLIUserDefinedTypeVariable  
			| PLICLOBLocatorVariable  
			| PLIBLOBLocatorVariable  
			| PLIUserDefinedTypeLocatorVariable  
			| PLIArrayLocatorVariable  
			| PLIMultisetLocatorVariable  
			| PLIREFVariable;;;
			PLICLOBVariable = ((str_p("SQL"))  >> "TYPE"   >> "IS"   >> "CLOB"   >> '('  >> LargeObjectLength  >> ')'  >> !((str_p("CHARACTER"))  >> "SET"  >> !(str_p("IS")) >> CharacterSetSpecification));;;
			PLIBLOBVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"   >> "BLOB"   >> '('  >> LargeObjectLength  >> ')' ;;;
			PLIUserDefinedTypeVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"  >> PathResolvedUserDefinedTypeName  >> "AS"  >> PredefinedType;;;
			PLICLOBLocatorVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"   >> "CLOB"   >> "AS"   >> "LOCATOR" ;;;
			PLIBLOBLocatorVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"   >> "BLOB"   >> "AS"   >> "LOCATOR" ;;;
			PLIUserDefinedTypeLocatorVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"  >> PathResolvedUserDefinedTypeName  >> "AS"   >> "LOCATOR" ;;;
			PLIArrayLocatorVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"  >> ArrayType  >> "AS"   >> "LOCATOR" ;;;
			PLIMultisetLocatorVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"  >> MultisetType  >> "AS"   >> "LOCATOR" ;;;
			PLIREFVariable =(str_p("SQL"))  >> "TYPE"   >> "IS"  >> ReferenceType;;;
			PLITypeFixedDecimal = ((str_p("DEC"))  
								   | "DECIMAL"   >> "FIXED" )  
			| (str_p("FIXED")  >> "DEC"   
			   | "DECIMAL" );;;
			PLITypeFixedBinary = (str_p("BIN")		
								  | "BINARY"   >> "FIXED" )  
			| (str_p("FIXED")  >> "BIN" 		
			   | "BINARY" );;;
			PLITypeFloatBinary = (str_p("BIN")		
								  | "BINARY"   >> "FLOAT" )  
			| ((str_p("FLOAT"))  >> "BIN" 		
			   | "BINARY" );;;
			DirectSQLStatement = DirectlyExecutableStatement  >> ';' ;;;
			DirectlyExecutableStatement = DirectSQLDataStatement  
			| SQLSchemaStatement  
			| SQLTransactionStatement  
			| SQLConnectionStatement  
			| SQLSessionStatement  
			| DirectImplementationDefinedStatement;;;
			DirectSQLDataStatement = DeleteStatementSearched  
			| DirectSelectStatementMultipleRows  
			| InsertStatement  
			| UpdateStatementSearched  
			| MergeStatement  
			| TemporaryTableDeclaration;;;
			DirectImplementationDefinedStatement = nothing_p;;;
			DirectSelectStatementMultipleRows = CursorSpecification;;;
			GetDiagnosticsStatement =(str_p("GET"))  >> "DIAGNOSTICS"  >> SQLDiagnosticsInformation;;;
			SQLDiagnosticsInformation = StatementInformation  
			| ConditionInformation;;;
			StatementInformation = ((StatementInformationItem%ch_p(',')));;;
			StatementInformationItem = SimpleTargetSpecification  >> '='  >> StatementInformationItemName;;;
			StatementInformationItemName =(str_p("NUMBER"))  
			| "MORE"   
			| "COMMAND_FUNCTION"   
			| "COMMAND_FUNCTION_CODE"   
			| "DYNAMIC_FUNCTION"   
			| "DYNAMIC_FUNCTION_CODE"   
			| "ROW_COUNT"   
			| "TRANSACTIONS_COMMITTED"   
			| "TRANSACTIONS_ROLLED_BACK"   
			| "TRANSACTION_ACTIVE" ;;;
			ConditionInformation = ((str_p("EXCEPTION"))  
									| "CONDITION"  >> ConditionNumber >> (ConditionInformationItem%ch_p(',')));;;
			ConditionInformationItem = SimpleTargetSpecification  >> '='  >> ConditionInformationItemName;;;
			ConditionInformationItemName =(str_p("CATALOG_NAME"))  
			| "CLASS_ORIGIN"   
			| "COLUMN_NAME"   
			| "CONDITION_NUMBER"   
			| "CONNECTION_NAME"   
			| "CONSTRAINT_CATALOG"   
			| "CONSTRAINT_NAME"   
			| "CONSTRAINT_SCHEMA"   
			| "CURSOR_NAME"   
			| "MESSAGE_LENGTH"   
			| "MESSAGE_OCTET_LENGTH"   
			| "MESSAGE_TEXT"   
			| "PARAMETER_MODE"   
			| "PARAMETER_NAME"   
			| "PARAMETER_ORDINAL_POSITION"   
			| "RETURNED_SQLSTATE"   
			| "ROUTINE_CATALOG"   
			| "ROUTINE_NAME"   
			| "ROUTINE_SCHEMA"   
			| "SCHEMA_NAME"   
			| "SERVER_NAME"   
			| "SPECIFIC_NAME"   
			| "SUBCLASS_ORIGIN"   
			| "TABLE_NAME"   
			| "TRIGGER_CATALOG"   
			| "TRIGGER_NAME"   
			| "TRIGGER_SCHEMA" ;;;
			
			BOOST_SPIRIT_DEBUG_RULE( SQLTerminalCharacter );
			BOOST_SPIRIT_DEBUG_RULE( SQLTerminalCharacter);
			BOOST_SPIRIT_DEBUG_RULE( SqlSpecialCharacters );
			BOOST_SPIRIT_DEBUG_RULE( Token );
			BOOST_SPIRIT_DEBUG_RULE( NondelimiterToken );
			BOOST_SPIRIT_DEBUG_RULE( RegularIdentifier );
			BOOST_SPIRIT_DEBUG_RULE( IdentifierBody );
			BOOST_SPIRIT_DEBUG_RULE( IdentifierPart );
			BOOST_SPIRIT_DEBUG_RULE( IdentifierStart );
			BOOST_SPIRIT_DEBUG_RULE( IdentifierExtend );
			BOOST_SPIRIT_DEBUG_RULE( LargeObjectLengthToken );
			BOOST_SPIRIT_DEBUG_RULE( Multiplier );
			BOOST_SPIRIT_DEBUG_RULE( UnicodeDelimitedIdentifier );
			BOOST_SPIRIT_DEBUG_RULE( UnicodeDelimiterBody );
			BOOST_SPIRIT_DEBUG_RULE( UnicodeIdentifierPart );
			BOOST_SPIRIT_DEBUG_RULE( UnicodeEscapeValue );
			BOOST_SPIRIT_DEBUG_RULE( Unicode4DigitEscapeValue );
			BOOST_SPIRIT_DEBUG_RULE( Unicode6DigitEscapeValue );
			BOOST_SPIRIT_DEBUG_RULE( EscapeCharacter );
			BOOST_SPIRIT_DEBUG_RULE( NondoublequoteCharacter );
			BOOST_SPIRIT_DEBUG_RULE( DoublequoteSymbol );
			BOOST_SPIRIT_DEBUG_RULE( DelimiterToken );
			BOOST_SPIRIT_DEBUG_RULE( NotEqualsOperator );
			BOOST_SPIRIT_DEBUG_RULE( GreaterThanOrEqualsOperator );
			BOOST_SPIRIT_DEBUG_RULE( LessThanOrEqualsOperator );
			BOOST_SPIRIT_DEBUG_RULE( ConcatenationOperator );
			BOOST_SPIRIT_DEBUG_RULE( RightArrow );
			BOOST_SPIRIT_DEBUG_RULE( DoubleColon );
			BOOST_SPIRIT_DEBUG_RULE( DoublePeriod );
			BOOST_SPIRIT_DEBUG_RULE( Separator );
			BOOST_SPIRIT_DEBUG_RULE( Comment );
			BOOST_SPIRIT_DEBUG_RULE( SimpleComment );
			BOOST_SPIRIT_DEBUG_RULE( SimpleCommentIntroducer );
			BOOST_SPIRIT_DEBUG_RULE( BracketedComment );
			BOOST_SPIRIT_DEBUG_RULE( BracketedCommentIntroducer );
			BOOST_SPIRIT_DEBUG_RULE( BracketedCommentTerminator );
			BOOST_SPIRIT_DEBUG_RULE( BracketedCommentContents );
			BOOST_SPIRIT_DEBUG_RULE( CommentCharacter );
			BOOST_SPIRIT_DEBUG_RULE( KeyWord );
			BOOST_SPIRIT_DEBUG_RULE( NonReservedWord );
			BOOST_SPIRIT_DEBUG_RULE( ReservedWord );
			BOOST_SPIRIT_DEBUG_RULE( Literal );
			BOOST_SPIRIT_DEBUG_RULE( UnsignedLiteral );
			BOOST_SPIRIT_DEBUG_RULE( GeneralLiteral );
			BOOST_SPIRIT_DEBUG_RULE( CharacterStringLiteral );
			BOOST_SPIRIT_DEBUG_RULE( Introducer );
			BOOST_SPIRIT_DEBUG_RULE( CharacterRepresentation );
			BOOST_SPIRIT_DEBUG_RULE( NonquoteCharacter );
			BOOST_SPIRIT_DEBUG_RULE( QuoteSymbol );
			BOOST_SPIRIT_DEBUG_RULE( NationalCharacterStringLiteral );
			BOOST_SPIRIT_DEBUG_RULE( UnicodeCharacterStringLiteral );
			BOOST_SPIRIT_DEBUG_RULE( UnicodeRepresentation );
			BOOST_SPIRIT_DEBUG_RULE( BinaryStringLiteral );
			BOOST_SPIRIT_DEBUG_RULE( SignedNumericLiteral );
			BOOST_SPIRIT_DEBUG_RULE( UnsignedNumericLiteral );
			BOOST_SPIRIT_DEBUG_RULE( ExactNumericLiteral );
			BOOST_SPIRIT_DEBUG_RULE( ApproximateNumericLiteral );
			BOOST_SPIRIT_DEBUG_RULE( Mantissa );
			BOOST_SPIRIT_DEBUG_RULE( Exponent );
			BOOST_SPIRIT_DEBUG_RULE( SignedInteger );
			BOOST_SPIRIT_DEBUG_RULE( DatetimeLiteral );
			BOOST_SPIRIT_DEBUG_RULE( DateLiteral );
			BOOST_SPIRIT_DEBUG_RULE( TimeLiteral );
			BOOST_SPIRIT_DEBUG_RULE( TimestampLiteral );
			BOOST_SPIRIT_DEBUG_RULE( DateString );
			BOOST_SPIRIT_DEBUG_RULE( TimeString );
			BOOST_SPIRIT_DEBUG_RULE( TimestampString );
			BOOST_SPIRIT_DEBUG_RULE( TimeZoneInterval );
			BOOST_SPIRIT_DEBUG_RULE( DateValue );
			BOOST_SPIRIT_DEBUG_RULE( TimeValue );
			BOOST_SPIRIT_DEBUG_RULE( IntervalLiteral );
			BOOST_SPIRIT_DEBUG_RULE( IntervalString );
			BOOST_SPIRIT_DEBUG_RULE( UnquotedDateString );
			BOOST_SPIRIT_DEBUG_RULE( UnquotedTimeString );
			BOOST_SPIRIT_DEBUG_RULE( UnquotedTimestampString );
			BOOST_SPIRIT_DEBUG_RULE( UnquotedIntervalString );
			BOOST_SPIRIT_DEBUG_RULE( YearMonthLiteral );
			BOOST_SPIRIT_DEBUG_RULE( DayTimeLiteral );
			BOOST_SPIRIT_DEBUG_RULE( DayTimeInterval );
			BOOST_SPIRIT_DEBUG_RULE( TimeInterval );
			BOOST_SPIRIT_DEBUG_RULE( YearsValue );
			BOOST_SPIRIT_DEBUG_RULE( MonthsValue );
			BOOST_SPIRIT_DEBUG_RULE( DaysValue );
			BOOST_SPIRIT_DEBUG_RULE( HoursValue );
			BOOST_SPIRIT_DEBUG_RULE( MinutesValue );
			BOOST_SPIRIT_DEBUG_RULE( SecondsValue );
			BOOST_SPIRIT_DEBUG_RULE( SecondsIntegerValue );
			BOOST_SPIRIT_DEBUG_RULE( SecondsFraction );
			BOOST_SPIRIT_DEBUG_RULE( DatetimeValue );
			BOOST_SPIRIT_DEBUG_RULE( BooleanLiteral );
			BOOST_SPIRIT_DEBUG_RULE( Identifier );
			BOOST_SPIRIT_DEBUG_RULE( ActualIdentifier );
			BOOST_SPIRIT_DEBUG_RULE( SQLLanguageIdentifier );
			BOOST_SPIRIT_DEBUG_RULE( SQLLanguageIdentifierStart );
			BOOST_SPIRIT_DEBUG_RULE( SQLLanguageIdentifierPart );
			BOOST_SPIRIT_DEBUG_RULE( AuthorizationIdentifier );
			BOOST_SPIRIT_DEBUG_RULE( TableName );
			BOOST_SPIRIT_DEBUG_RULE( DomainName );
			BOOST_SPIRIT_DEBUG_RULE( SchemaName );
			BOOST_SPIRIT_DEBUG_RULE( CatalogName );
			BOOST_SPIRIT_DEBUG_RULE( SchemaQualifiedName );
			BOOST_SPIRIT_DEBUG_RULE( LocalOrSchemaQualifiedName );
			BOOST_SPIRIT_DEBUG_RULE( LocalOrSchemaQualifier );
			BOOST_SPIRIT_DEBUG_RULE( QualifiedIdentifier );
			BOOST_SPIRIT_DEBUG_RULE( ColumnName );
			BOOST_SPIRIT_DEBUG_RULE( CorrelationName );
			BOOST_SPIRIT_DEBUG_RULE( QueryName );
			BOOST_SPIRIT_DEBUG_RULE( SQLClientModuleName );
			BOOST_SPIRIT_DEBUG_RULE( ProcedureName );
			BOOST_SPIRIT_DEBUG_RULE( SchemaQualifiedRoutineName );
			BOOST_SPIRIT_DEBUG_RULE( MethodName );
			BOOST_SPIRIT_DEBUG_RULE( SpecificName );
			BOOST_SPIRIT_DEBUG_RULE( CursorName );
			BOOST_SPIRIT_DEBUG_RULE( LocalQualifiedName );
			BOOST_SPIRIT_DEBUG_RULE( LocalQualifier );
			BOOST_SPIRIT_DEBUG_RULE( HostParameterName );
			BOOST_SPIRIT_DEBUG_RULE( SQLParameterName );
			BOOST_SPIRIT_DEBUG_RULE( ConstraintName );
			BOOST_SPIRIT_DEBUG_RULE( ExternalRoutineName );
			BOOST_SPIRIT_DEBUG_RULE( TriggerName );
			BOOST_SPIRIT_DEBUG_RULE( CollationName );
			BOOST_SPIRIT_DEBUG_RULE( CharacterSetName );
			BOOST_SPIRIT_DEBUG_RULE( TransliterationName );
			BOOST_SPIRIT_DEBUG_RULE( TranscodingName );
			BOOST_SPIRIT_DEBUG_RULE( UserDefinedTypeName );
			BOOST_SPIRIT_DEBUG_RULE( SchemaResolvedUserDefinedTypeName );
			BOOST_SPIRIT_DEBUG_RULE( SchemaQualifiedTypeName );
			BOOST_SPIRIT_DEBUG_RULE( AttributeName );
			BOOST_SPIRIT_DEBUG_RULE( FieldName );
			BOOST_SPIRIT_DEBUG_RULE( SavepointName );
			BOOST_SPIRIT_DEBUG_RULE( SequenceGeneratorName );
			BOOST_SPIRIT_DEBUG_RULE( RoleName );
			BOOST_SPIRIT_DEBUG_RULE( UserIdentifier );
			BOOST_SPIRIT_DEBUG_RULE( ConnectionName );
			BOOST_SPIRIT_DEBUG_RULE( SQLServerName );
			BOOST_SPIRIT_DEBUG_RULE( ConnectionUserName );
			BOOST_SPIRIT_DEBUG_RULE( SQLStatementName );
			BOOST_SPIRIT_DEBUG_RULE( StatementName );
			BOOST_SPIRIT_DEBUG_RULE( ExtendedStatementName );
			BOOST_SPIRIT_DEBUG_RULE( DynamicCursorName );
			BOOST_SPIRIT_DEBUG_RULE( ExtendedCursorName );
			BOOST_SPIRIT_DEBUG_RULE( DescriptorName );
			BOOST_SPIRIT_DEBUG_RULE( ScopeOption );
			BOOST_SPIRIT_DEBUG_RULE( WindowName );
			BOOST_SPIRIT_DEBUG_RULE( DataType );
			BOOST_SPIRIT_DEBUG_RULE( PredefinedType );
			BOOST_SPIRIT_DEBUG_RULE( CharacterStringType );
			BOOST_SPIRIT_DEBUG_RULE( NationalCharacterStringType );
			BOOST_SPIRIT_DEBUG_RULE( BinaryLargeObjectStringType );
			BOOST_SPIRIT_DEBUG_RULE( NumericType );
			BOOST_SPIRIT_DEBUG_RULE( ExactNumericType );
			BOOST_SPIRIT_DEBUG_RULE( ApproximateNumericType );
			BOOST_SPIRIT_DEBUG_RULE( Length );
			BOOST_SPIRIT_DEBUG_RULE( LargeObjectLength );
			BOOST_SPIRIT_DEBUG_RULE( CharLengthUnits );
			BOOST_SPIRIT_DEBUG_RULE( Precision );
			BOOST_SPIRIT_DEBUG_RULE( Scale );
			BOOST_SPIRIT_DEBUG_RULE( BooleanType );
			BOOST_SPIRIT_DEBUG_RULE( DatetimeType );
			BOOST_SPIRIT_DEBUG_RULE( WithOrWithoutTimeZone );
			BOOST_SPIRIT_DEBUG_RULE( TimePrecision );
			BOOST_SPIRIT_DEBUG_RULE( TimestampPrecision );
			BOOST_SPIRIT_DEBUG_RULE( TimeFractionalSecondsPrecision );
			BOOST_SPIRIT_DEBUG_RULE( IntervalType );
			BOOST_SPIRIT_DEBUG_RULE( RowType );
			BOOST_SPIRIT_DEBUG_RULE( RowTypeBody );
			BOOST_SPIRIT_DEBUG_RULE( ReferenceType );
			BOOST_SPIRIT_DEBUG_RULE( ScopeClause );
			BOOST_SPIRIT_DEBUG_RULE( ReferencedType );
			BOOST_SPIRIT_DEBUG_RULE( PathResolvedUserDefinedTypeName );
			BOOST_SPIRIT_DEBUG_RULE( PathResolvedUserDefinedTypeName );
			BOOST_SPIRIT_DEBUG_RULE( CollectionType );
			BOOST_SPIRIT_DEBUG_RULE( ArrayType );
			BOOST_SPIRIT_DEBUG_RULE( MultisetType );
			BOOST_SPIRIT_DEBUG_RULE( FieldDefinition );
			BOOST_SPIRIT_DEBUG_RULE( ValueExpressionPrimary );
			BOOST_SPIRIT_DEBUG_RULE( ParenthesizedValueExpression );
			BOOST_SPIRIT_DEBUG_RULE( NonparenthesizedValueExpressionPrimary );
			BOOST_SPIRIT_DEBUG_RULE( ValueSpecification );
			BOOST_SPIRIT_DEBUG_RULE( UnsignedValueSpecification );
			BOOST_SPIRIT_DEBUG_RULE( GeneralValueSpecification );
			BOOST_SPIRIT_DEBUG_RULE( SimpleValueSpecification );
			BOOST_SPIRIT_DEBUG_RULE( TargetSpecification );
			BOOST_SPIRIT_DEBUG_RULE( SimpleTargetSpecification );
			BOOST_SPIRIT_DEBUG_RULE( HostParameterSpecification );
			BOOST_SPIRIT_DEBUG_RULE( DynamicParameterSpecification );
			BOOST_SPIRIT_DEBUG_RULE( EmbeddedVariableSpecification );
			BOOST_SPIRIT_DEBUG_RULE( IndicatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( IndicatorParameter );
			BOOST_SPIRIT_DEBUG_RULE( TargetArrayElementSpecification );
			BOOST_SPIRIT_DEBUG_RULE( TargetArrayReference );
			BOOST_SPIRIT_DEBUG_RULE( CurrentCollationSpecification );
			BOOST_SPIRIT_DEBUG_RULE( ContextuallyTypedValueSpecification );
			BOOST_SPIRIT_DEBUG_RULE( ImplicitlyTypedValueSpecification );
			BOOST_SPIRIT_DEBUG_RULE( NullSpecification );
			BOOST_SPIRIT_DEBUG_RULE( EmptySpecification );
			BOOST_SPIRIT_DEBUG_RULE( DefaultSpecification );
			BOOST_SPIRIT_DEBUG_RULE( IdentifierChain );
			BOOST_SPIRIT_DEBUG_RULE( BasicIdentifierChain );
			BOOST_SPIRIT_DEBUG_RULE( ColumnReference );
			BOOST_SPIRIT_DEBUG_RULE( SQLParameterReference );
			BOOST_SPIRIT_DEBUG_RULE( SetFunctionSpecification );
			BOOST_SPIRIT_DEBUG_RULE( GroupingOperation );
			BOOST_SPIRIT_DEBUG_RULE( WindowFunction );
			BOOST_SPIRIT_DEBUG_RULE( WindowFunctionType );
			BOOST_SPIRIT_DEBUG_RULE( RankFunctionType );
			BOOST_SPIRIT_DEBUG_RULE( WindowNameOrSpecification );
			BOOST_SPIRIT_DEBUG_RULE( InLineWindowSpecification );
			BOOST_SPIRIT_DEBUG_RULE( CaseExpression );
			BOOST_SPIRIT_DEBUG_RULE( CaseAbbreviation );
			BOOST_SPIRIT_DEBUG_RULE( CaseSpecification );
			BOOST_SPIRIT_DEBUG_RULE( SimpleCase );
			BOOST_SPIRIT_DEBUG_RULE( SearchedCase );
			BOOST_SPIRIT_DEBUG_RULE( SimpleWhenClause );
			BOOST_SPIRIT_DEBUG_RULE( SearchedWhenClause );
			BOOST_SPIRIT_DEBUG_RULE( ElseClause );
			BOOST_SPIRIT_DEBUG_RULE( CaseOperand );
			BOOST_SPIRIT_DEBUG_RULE( WhenOperand );
			BOOST_SPIRIT_DEBUG_RULE( Result );
			BOOST_SPIRIT_DEBUG_RULE( ResultExpression );
			BOOST_SPIRIT_DEBUG_RULE( CastSpecification );
			BOOST_SPIRIT_DEBUG_RULE( CastOperand );
			BOOST_SPIRIT_DEBUG_RULE( CastTarget );
			BOOST_SPIRIT_DEBUG_RULE( NextValueExpression );
			BOOST_SPIRIT_DEBUG_RULE( FieldReference );
			BOOST_SPIRIT_DEBUG_RULE( SubtypeTreatment );
			BOOST_SPIRIT_DEBUG_RULE( SubtypeOperand );
			BOOST_SPIRIT_DEBUG_RULE( TargetSubtype );
			BOOST_SPIRIT_DEBUG_RULE( MethodInvocation );
			BOOST_SPIRIT_DEBUG_RULE( DirectInvocation );
			BOOST_SPIRIT_DEBUG_RULE( GeneralizedInvocation );
			BOOST_SPIRIT_DEBUG_RULE( MethodSelection );
			BOOST_SPIRIT_DEBUG_RULE( ConstructorMethodSelection );
			BOOST_SPIRIT_DEBUG_RULE( StaticMethodInvocation );
			BOOST_SPIRIT_DEBUG_RULE( StaticMethodSelection );
			BOOST_SPIRIT_DEBUG_RULE( NewSpecification );
			BOOST_SPIRIT_DEBUG_RULE( NewInvocation );
			BOOST_SPIRIT_DEBUG_RULE( AttributeOrMethodReference );
			BOOST_SPIRIT_DEBUG_RULE( DereferenceOperator );
			BOOST_SPIRIT_DEBUG_RULE( DereferenceOperation );
			BOOST_SPIRIT_DEBUG_RULE( MethodReference );
			BOOST_SPIRIT_DEBUG_RULE( ReferenceResolution );
			BOOST_SPIRIT_DEBUG_RULE( ArrayElementReference );
			BOOST_SPIRIT_DEBUG_RULE( MultisetElementReference );
			BOOST_SPIRIT_DEBUG_RULE( ValueExpression );
			BOOST_SPIRIT_DEBUG_RULE( CommonValueExpression );
			BOOST_SPIRIT_DEBUG_RULE( UserDefinedTypeValueExpression );
			BOOST_SPIRIT_DEBUG_RULE( ReferenceValueExpression );
			BOOST_SPIRIT_DEBUG_RULE( CollectionValueExpression );
			BOOST_SPIRIT_DEBUG_RULE( CollectionValueConstructor );
			BOOST_SPIRIT_DEBUG_RULE( NumericValueExpression );
			BOOST_SPIRIT_DEBUG_RULE( Term );
			BOOST_SPIRIT_DEBUG_RULE( Factor );
			BOOST_SPIRIT_DEBUG_RULE( NumericPrimary );
			BOOST_SPIRIT_DEBUG_RULE( NumericValueFunction );
			BOOST_SPIRIT_DEBUG_RULE( PositionExpression );
			BOOST_SPIRIT_DEBUG_RULE( StringPositionExpression );
			BOOST_SPIRIT_DEBUG_RULE( BlobPositionExpression );
			BOOST_SPIRIT_DEBUG_RULE( LengthExpression );
			BOOST_SPIRIT_DEBUG_RULE( CharLengthExpression );
			BOOST_SPIRIT_DEBUG_RULE( OctetLengthExpression );
			BOOST_SPIRIT_DEBUG_RULE( ExtractExpression );
			BOOST_SPIRIT_DEBUG_RULE( ExtractField );
			BOOST_SPIRIT_DEBUG_RULE( TimeZoneField );
			BOOST_SPIRIT_DEBUG_RULE( ExtractSource );
			BOOST_SPIRIT_DEBUG_RULE( CardinalityExpression );
			BOOST_SPIRIT_DEBUG_RULE( AbsoluteValueExpression );
			BOOST_SPIRIT_DEBUG_RULE( ModulusExpression );
			BOOST_SPIRIT_DEBUG_RULE( NaturalLogarithm );
			BOOST_SPIRIT_DEBUG_RULE( ExponentialFunction );
			BOOST_SPIRIT_DEBUG_RULE( PowerFunction );
			BOOST_SPIRIT_DEBUG_RULE( NumericValueExpressionBase );
			BOOST_SPIRIT_DEBUG_RULE( NumericValueExpressionExponent );
			BOOST_SPIRIT_DEBUG_RULE( SquareRoot );
			BOOST_SPIRIT_DEBUG_RULE( FloorFunction );
			BOOST_SPIRIT_DEBUG_RULE( CeilingFunction );
			BOOST_SPIRIT_DEBUG_RULE( WidthBucketFunction );
			BOOST_SPIRIT_DEBUG_RULE( WidthBucketOperand );
			BOOST_SPIRIT_DEBUG_RULE( WidthBucketBound1 );
			BOOST_SPIRIT_DEBUG_RULE( WidthBucketBound2 );
			BOOST_SPIRIT_DEBUG_RULE( WidthBucketCount );
			BOOST_SPIRIT_DEBUG_RULE( StringValueExpression );
			BOOST_SPIRIT_DEBUG_RULE( CharacterValueExpression );
			BOOST_SPIRIT_DEBUG_RULE( Concatenation );
			BOOST_SPIRIT_DEBUG_RULE( CharacterFactor );
			BOOST_SPIRIT_DEBUG_RULE( CharacterPrimary );
			BOOST_SPIRIT_DEBUG_RULE( BlobValueExpression );
			BOOST_SPIRIT_DEBUG_RULE( BlobFactor );
			BOOST_SPIRIT_DEBUG_RULE( BlobPrimary );
			BOOST_SPIRIT_DEBUG_RULE( BlobConcatenation );
			BOOST_SPIRIT_DEBUG_RULE( StringValueFunction );
			BOOST_SPIRIT_DEBUG_RULE( CharacterValueFunction );
			BOOST_SPIRIT_DEBUG_RULE( CharacterSubstringFunction );
			BOOST_SPIRIT_DEBUG_RULE( RegularExpressionSubstringFunction );
			BOOST_SPIRIT_DEBUG_RULE( Fold );
			BOOST_SPIRIT_DEBUG_RULE( Transcoding );
			BOOST_SPIRIT_DEBUG_RULE( CharacterTransliteration );
			BOOST_SPIRIT_DEBUG_RULE( TrimFunction );
			BOOST_SPIRIT_DEBUG_RULE( TrimOperands );
			BOOST_SPIRIT_DEBUG_RULE( TrimSource );
			BOOST_SPIRIT_DEBUG_RULE( TrimSpecification );
			BOOST_SPIRIT_DEBUG_RULE( TrimCharacter );
			BOOST_SPIRIT_DEBUG_RULE( CharacterOverlayFunction );
			BOOST_SPIRIT_DEBUG_RULE( NormalizeFunction );
			BOOST_SPIRIT_DEBUG_RULE( SpecificTypeMethod );
			BOOST_SPIRIT_DEBUG_RULE( BlobValueFunction );
			BOOST_SPIRIT_DEBUG_RULE( BlobSubstringFunction );
			BOOST_SPIRIT_DEBUG_RULE( BlobTrimFunction );
			BOOST_SPIRIT_DEBUG_RULE( BlobTrimOperands );
			BOOST_SPIRIT_DEBUG_RULE( BlobTrimSource );
			BOOST_SPIRIT_DEBUG_RULE( TrimOctet );
			BOOST_SPIRIT_DEBUG_RULE( BlobOverlayFunction );
			BOOST_SPIRIT_DEBUG_RULE( StartPosition );
			BOOST_SPIRIT_DEBUG_RULE( StringLength );
			BOOST_SPIRIT_DEBUG_RULE( DatetimeValueExpression );
			BOOST_SPIRIT_DEBUG_RULE( DatetimeTerm );
			BOOST_SPIRIT_DEBUG_RULE( DatetimeFactor );
			BOOST_SPIRIT_DEBUG_RULE( DatetimePrimary );
			BOOST_SPIRIT_DEBUG_RULE( TimeZone );
			BOOST_SPIRIT_DEBUG_RULE( TimeZoneSpecifier );
			BOOST_SPIRIT_DEBUG_RULE( DatetimeValueFunction );
			BOOST_SPIRIT_DEBUG_RULE( CurrentDateValueFunction );
			BOOST_SPIRIT_DEBUG_RULE( CurrentTimeValueFunction );
			BOOST_SPIRIT_DEBUG_RULE( CurrentLocalTimeValueFunction );
			BOOST_SPIRIT_DEBUG_RULE( CurrentTimestampValueFunction );
			BOOST_SPIRIT_DEBUG_RULE( CurrentLocalTimestampValueFunction );
			BOOST_SPIRIT_DEBUG_RULE( IntervalValueExpression );
			BOOST_SPIRIT_DEBUG_RULE( IntervalTerm );
			BOOST_SPIRIT_DEBUG_RULE( IntervalFactor );
			BOOST_SPIRIT_DEBUG_RULE( IntervalPrimary );
			BOOST_SPIRIT_DEBUG_RULE( IntervalValueExpression1 );
			BOOST_SPIRIT_DEBUG_RULE( IntervalTerm1 );
			BOOST_SPIRIT_DEBUG_RULE( IntervalTerm2 );
			BOOST_SPIRIT_DEBUG_RULE( IntervalValueFunction );
			BOOST_SPIRIT_DEBUG_RULE( IntervalAbsoluteValueFunction );
			BOOST_SPIRIT_DEBUG_RULE( BooleanValueExpression );
			BOOST_SPIRIT_DEBUG_RULE( BooleanTerm );
			BOOST_SPIRIT_DEBUG_RULE( BooleanFactor );
			BOOST_SPIRIT_DEBUG_RULE( BooleanTest );
			BOOST_SPIRIT_DEBUG_RULE( TruthValue );
			BOOST_SPIRIT_DEBUG_RULE( BooleanPrimary );
			BOOST_SPIRIT_DEBUG_RULE( BooleanPredicand );
			BOOST_SPIRIT_DEBUG_RULE( ParenthesizedBooleanValueExpression );
			BOOST_SPIRIT_DEBUG_RULE( ArrayValueExpression );
			BOOST_SPIRIT_DEBUG_RULE( ArrayConcatenation );
			BOOST_SPIRIT_DEBUG_RULE( ArrayValueExpression1 );
			BOOST_SPIRIT_DEBUG_RULE( ArrayFactor );
			BOOST_SPIRIT_DEBUG_RULE( ArrayValueConstructor );
			BOOST_SPIRIT_DEBUG_RULE( ArrayValueConstructorByEnumeration );
			BOOST_SPIRIT_DEBUG_RULE( ArrayElementList );
			BOOST_SPIRIT_DEBUG_RULE( ArrayElement );
			BOOST_SPIRIT_DEBUG_RULE( ArrayValueConstructorByQuery );
			BOOST_SPIRIT_DEBUG_RULE( MultisetValueExpression );
			BOOST_SPIRIT_DEBUG_RULE( MultisetTerm );
			BOOST_SPIRIT_DEBUG_RULE( MultisetPrimary );
			BOOST_SPIRIT_DEBUG_RULE( MultisetValueFunction );
			BOOST_SPIRIT_DEBUG_RULE( MultisetSetFunction );
			BOOST_SPIRIT_DEBUG_RULE( MultisetValueConstructor );
			BOOST_SPIRIT_DEBUG_RULE( MultisetValueConstructorByEnumeration );
			BOOST_SPIRIT_DEBUG_RULE( MultisetElementList );
			BOOST_SPIRIT_DEBUG_RULE( MultisetElement );
			BOOST_SPIRIT_DEBUG_RULE( MultisetValueConstructorByQuery );
			BOOST_SPIRIT_DEBUG_RULE( TableValueConstructorByQuery );
			BOOST_SPIRIT_DEBUG_RULE( RowValueConstructor );
			BOOST_SPIRIT_DEBUG_RULE( ExplicitRowValueConstructor );
			BOOST_SPIRIT_DEBUG_RULE( RowValueConstructorElementList );
			BOOST_SPIRIT_DEBUG_RULE( RowValueConstructorElement );
			BOOST_SPIRIT_DEBUG_RULE( ContextuallyTypedRowValueConstructor );
			BOOST_SPIRIT_DEBUG_RULE( ContextuallyTypedRowValueConstructorElementList );
			BOOST_SPIRIT_DEBUG_RULE( ContextuallyTypedRowValueConstructorElement );
			BOOST_SPIRIT_DEBUG_RULE( RowValueConstructorPredicand );
			BOOST_SPIRIT_DEBUG_RULE( RowValueExpression );
			BOOST_SPIRIT_DEBUG_RULE( TableRowValueExpression );
			BOOST_SPIRIT_DEBUG_RULE( ContextuallyTypedRowValueExpression );
			BOOST_SPIRIT_DEBUG_RULE( RowValuePredicand );
			BOOST_SPIRIT_DEBUG_RULE( RowValueSpecialCase );
			BOOST_SPIRIT_DEBUG_RULE( TableValueConstructor );
			BOOST_SPIRIT_DEBUG_RULE( RowValueExpressionList );
			BOOST_SPIRIT_DEBUG_RULE( ContextuallyTypedTableValueConstructor );
			BOOST_SPIRIT_DEBUG_RULE( ContextuallyTypedRowValueExpressionList );
			BOOST_SPIRIT_DEBUG_RULE( TableExpression );
			BOOST_SPIRIT_DEBUG_RULE( FromClause );
			BOOST_SPIRIT_DEBUG_RULE( TableReferenceList );
			BOOST_SPIRIT_DEBUG_RULE( TableReference );
			BOOST_SPIRIT_DEBUG_RULE( TablePrimaryOrJoinedTable );
			BOOST_SPIRIT_DEBUG_RULE( SampleClause );
			BOOST_SPIRIT_DEBUG_RULE( SampleMethod );
			BOOST_SPIRIT_DEBUG_RULE( RepeatableClause );
			BOOST_SPIRIT_DEBUG_RULE( SamplePercentage );
			BOOST_SPIRIT_DEBUG_RULE( RepeatArgument );
			BOOST_SPIRIT_DEBUG_RULE( TablePrimary );
			BOOST_SPIRIT_DEBUG_RULE( OnlySpec );
			BOOST_SPIRIT_DEBUG_RULE( LateralDerivedTable );
			BOOST_SPIRIT_DEBUG_RULE( CollectionDerivedTable );
			BOOST_SPIRIT_DEBUG_RULE( TableFunctionDerivedTable );
			BOOST_SPIRIT_DEBUG_RULE( DerivedTable );
			BOOST_SPIRIT_DEBUG_RULE( TableOrQueryName );
			BOOST_SPIRIT_DEBUG_RULE( DerivedColumnList );
			BOOST_SPIRIT_DEBUG_RULE( ColumnNameList );
			BOOST_SPIRIT_DEBUG_RULE( JoinedTable );
			BOOST_SPIRIT_DEBUG_RULE( CrossJoin );
			BOOST_SPIRIT_DEBUG_RULE( QualifiedJoin );
			BOOST_SPIRIT_DEBUG_RULE( NaturalJoin );
			BOOST_SPIRIT_DEBUG_RULE( UnionJoin );
			BOOST_SPIRIT_DEBUG_RULE( JoinSpecification );
			BOOST_SPIRIT_DEBUG_RULE( JoinCondition );
			BOOST_SPIRIT_DEBUG_RULE( NamedColumnsJoin );
			BOOST_SPIRIT_DEBUG_RULE( JoinType );
			BOOST_SPIRIT_DEBUG_RULE( OuterJoinType );
			BOOST_SPIRIT_DEBUG_RULE( JoinColumnList );
			BOOST_SPIRIT_DEBUG_RULE( WhereClause );
			BOOST_SPIRIT_DEBUG_RULE( GroupByClause );
			BOOST_SPIRIT_DEBUG_RULE( GroupingElementList );
			BOOST_SPIRIT_DEBUG_RULE( GroupingElement );
			BOOST_SPIRIT_DEBUG_RULE( OrdinaryGroupingSet );
			BOOST_SPIRIT_DEBUG_RULE( GroupingColumnReference );
			BOOST_SPIRIT_DEBUG_RULE( GroupingColumnReferenceList );
			BOOST_SPIRIT_DEBUG_RULE( RollupList );
			BOOST_SPIRIT_DEBUG_RULE( OrdinaryGroupingSetList );
			BOOST_SPIRIT_DEBUG_RULE( CubeList );
			BOOST_SPIRIT_DEBUG_RULE( GroupingSetsSpecification );
			BOOST_SPIRIT_DEBUG_RULE( GroupingSetList );
			BOOST_SPIRIT_DEBUG_RULE( GroupingSet );
			BOOST_SPIRIT_DEBUG_RULE( EmptyGroupingSet );
			BOOST_SPIRIT_DEBUG_RULE( HavingClause );
			BOOST_SPIRIT_DEBUG_RULE( WindowClause );
			BOOST_SPIRIT_DEBUG_RULE( WindowDefinitionList );
			BOOST_SPIRIT_DEBUG_RULE( WindowDefinition );
			BOOST_SPIRIT_DEBUG_RULE( NewWindowName );
			BOOST_SPIRIT_DEBUG_RULE( WindowSpecification );
			BOOST_SPIRIT_DEBUG_RULE( WindowSpecificationDetails );
			BOOST_SPIRIT_DEBUG_RULE( ExistingWindowName );
			BOOST_SPIRIT_DEBUG_RULE( WindowPartitionClause );
			BOOST_SPIRIT_DEBUG_RULE( WindowPartitionColumnReferenceList );
			BOOST_SPIRIT_DEBUG_RULE( WindowPartitionColumnReference );
			BOOST_SPIRIT_DEBUG_RULE( WindowOrderClause );
			BOOST_SPIRIT_DEBUG_RULE( WindowFrameClause );
			BOOST_SPIRIT_DEBUG_RULE( WindowFrameUnits );
			BOOST_SPIRIT_DEBUG_RULE( WindowFrameExtent );
			BOOST_SPIRIT_DEBUG_RULE( WindowFrameStart );
			BOOST_SPIRIT_DEBUG_RULE( WindowFramePreceding );
			BOOST_SPIRIT_DEBUG_RULE( WindowFrameBetween );
			BOOST_SPIRIT_DEBUG_RULE( WindowFrameBound1 );
			BOOST_SPIRIT_DEBUG_RULE( WindowFrameBound2 );
			BOOST_SPIRIT_DEBUG_RULE( WindowFrameBound );
			BOOST_SPIRIT_DEBUG_RULE( WindowFrameFollowing );
			BOOST_SPIRIT_DEBUG_RULE( WindowFrameExclusion );
			BOOST_SPIRIT_DEBUG_RULE( QuerySpecification );
			BOOST_SPIRIT_DEBUG_RULE( SelectList );
			BOOST_SPIRIT_DEBUG_RULE( SelectSublist );
			BOOST_SPIRIT_DEBUG_RULE( QualifiedAsterisk );
			BOOST_SPIRIT_DEBUG_RULE( AsteriskedIdentifierChain );
			BOOST_SPIRIT_DEBUG_RULE( AsteriskedIdentifier );
			BOOST_SPIRIT_DEBUG_RULE( DerivedColumn );
			BOOST_SPIRIT_DEBUG_RULE( AsClause );
			BOOST_SPIRIT_DEBUG_RULE( AllFieldsReference );
			BOOST_SPIRIT_DEBUG_RULE( AllFieldsColumnNameList );
			BOOST_SPIRIT_DEBUG_RULE( QueryExpression );
			BOOST_SPIRIT_DEBUG_RULE( WithClause );
			BOOST_SPIRIT_DEBUG_RULE( WithList );
			BOOST_SPIRIT_DEBUG_RULE( WithListElement );
			BOOST_SPIRIT_DEBUG_RULE( WithColumnList );
			BOOST_SPIRIT_DEBUG_RULE( QueryExpressionBody );
			BOOST_SPIRIT_DEBUG_RULE( NonJoinQueryExpression );
			BOOST_SPIRIT_DEBUG_RULE( QueryTerm );
			BOOST_SPIRIT_DEBUG_RULE( NonJoinQueryTerm );
			BOOST_SPIRIT_DEBUG_RULE( QueryPrimary );
			BOOST_SPIRIT_DEBUG_RULE( NonJoinQueryPrimary );
			BOOST_SPIRIT_DEBUG_RULE( SimpleTable );
			BOOST_SPIRIT_DEBUG_RULE( ExplicitTable );
			BOOST_SPIRIT_DEBUG_RULE( CorrespondingSpec );
			BOOST_SPIRIT_DEBUG_RULE( CorrespondingColumnList );
			BOOST_SPIRIT_DEBUG_RULE( SearchOrCycleClause );
			BOOST_SPIRIT_DEBUG_RULE( SearchClause );
			BOOST_SPIRIT_DEBUG_RULE( RecursiveSearchOrder );
			BOOST_SPIRIT_DEBUG_RULE( SequenceColumn );
			BOOST_SPIRIT_DEBUG_RULE( CycleClause );
			BOOST_SPIRIT_DEBUG_RULE( CycleColumnList );
			BOOST_SPIRIT_DEBUG_RULE( CycleColumn );
			BOOST_SPIRIT_DEBUG_RULE( CycleMarkColumn );
			BOOST_SPIRIT_DEBUG_RULE( PathColumn );
			BOOST_SPIRIT_DEBUG_RULE( CycleMarkValue );
			BOOST_SPIRIT_DEBUG_RULE( NonCycleMarkValue );
			BOOST_SPIRIT_DEBUG_RULE( ScalarSubquery );
			BOOST_SPIRIT_DEBUG_RULE( RowSubquery );
			BOOST_SPIRIT_DEBUG_RULE( TableSubquery );
			BOOST_SPIRIT_DEBUG_RULE( Subquery );
			BOOST_SPIRIT_DEBUG_RULE( Predicate );
			BOOST_SPIRIT_DEBUG_RULE( ComparisonPredicate );
			BOOST_SPIRIT_DEBUG_RULE( ComparisonPredicatePart2 );
			BOOST_SPIRIT_DEBUG_RULE( CompOp );
			BOOST_SPIRIT_DEBUG_RULE( BetweenPredicate );
			BOOST_SPIRIT_DEBUG_RULE( BetweenPredicatePart2 );
			BOOST_SPIRIT_DEBUG_RULE( InPredicate );
			BOOST_SPIRIT_DEBUG_RULE( InPredicatePart2 );
			BOOST_SPIRIT_DEBUG_RULE( InPredicateValue );
			BOOST_SPIRIT_DEBUG_RULE( InValueList );
			BOOST_SPIRIT_DEBUG_RULE( LikePredicate );
			BOOST_SPIRIT_DEBUG_RULE( CharacterLikePredicate );
			BOOST_SPIRIT_DEBUG_RULE( CharacterLikePredicatePart2 );
			BOOST_SPIRIT_DEBUG_RULE( CharacterPattern );
			BOOST_SPIRIT_DEBUG_RULE( EscapeCharacter );
			BOOST_SPIRIT_DEBUG_RULE( OctetLikePredicate );
			BOOST_SPIRIT_DEBUG_RULE( OctetLikePredicatePart2 );
			BOOST_SPIRIT_DEBUG_RULE( OctetPattern );
			BOOST_SPIRIT_DEBUG_RULE( EscapeOctet );
			BOOST_SPIRIT_DEBUG_RULE( SimilarPredicate );
			BOOST_SPIRIT_DEBUG_RULE( SimilarPredicatePart2 );
			BOOST_SPIRIT_DEBUG_RULE( SimilarPattern );
			BOOST_SPIRIT_DEBUG_RULE( RegularExpression );
			BOOST_SPIRIT_DEBUG_RULE( RegularTerm );
			BOOST_SPIRIT_DEBUG_RULE( RegularFactor );
			BOOST_SPIRIT_DEBUG_RULE( RepeatFactor );
			BOOST_SPIRIT_DEBUG_RULE( UpperLimit );
			BOOST_SPIRIT_DEBUG_RULE( LowValue );
			BOOST_SPIRIT_DEBUG_RULE( HighValue );
			BOOST_SPIRIT_DEBUG_RULE( RegularPrimary );
			BOOST_SPIRIT_DEBUG_RULE( CharacterSpecifier );
			BOOST_SPIRIT_DEBUG_RULE( NonEscapedCharacter );
			BOOST_SPIRIT_DEBUG_RULE( EscapedCharacter );
			BOOST_SPIRIT_DEBUG_RULE( RegularCharacterSet );
			BOOST_SPIRIT_DEBUG_RULE( CharacterEnumerationInclude );
			BOOST_SPIRIT_DEBUG_RULE( CharacterEnumerationExclude );
			BOOST_SPIRIT_DEBUG_RULE( CharacterEnumeration );
			BOOST_SPIRIT_DEBUG_RULE( RegularCharacterSetIdentifier );
			BOOST_SPIRIT_DEBUG_RULE( NullPredicate );
			BOOST_SPIRIT_DEBUG_RULE( NullPredicatePart2 );
			BOOST_SPIRIT_DEBUG_RULE( QuantifiedComparisonPredicate );
			BOOST_SPIRIT_DEBUG_RULE( QuantifiedComparisonPredicatePart2 );
			BOOST_SPIRIT_DEBUG_RULE( Quantifier );
			BOOST_SPIRIT_DEBUG_RULE( All );
			BOOST_SPIRIT_DEBUG_RULE( Some );
			BOOST_SPIRIT_DEBUG_RULE( ExistsPredicate );
			BOOST_SPIRIT_DEBUG_RULE( UniquePredicate );
			BOOST_SPIRIT_DEBUG_RULE( NormalizedPredicate );
			BOOST_SPIRIT_DEBUG_RULE( MatchPredicate );
			BOOST_SPIRIT_DEBUG_RULE( MatchPredicatePart2 );
			BOOST_SPIRIT_DEBUG_RULE( OverlapsPredicate );
			BOOST_SPIRIT_DEBUG_RULE( OverlapsPredicatePart1 );
			BOOST_SPIRIT_DEBUG_RULE( OverlapsPredicatePart2 );
			BOOST_SPIRIT_DEBUG_RULE( RowValuePredicand1 );
			BOOST_SPIRIT_DEBUG_RULE( RowValuePredicand2 );
			BOOST_SPIRIT_DEBUG_RULE( DistinctPredicate );
			BOOST_SPIRIT_DEBUG_RULE( DistinctPredicatePart2 );
			BOOST_SPIRIT_DEBUG_RULE( RowValuePredicand3 );
			BOOST_SPIRIT_DEBUG_RULE( RowValuePredicand4 );
			BOOST_SPIRIT_DEBUG_RULE( MemberPredicate );
			BOOST_SPIRIT_DEBUG_RULE( MemberPredicatePart2 );
			BOOST_SPIRIT_DEBUG_RULE( SubmultisetPredicate );
			BOOST_SPIRIT_DEBUG_RULE( SubmultisetPredicatePart2 );
			BOOST_SPIRIT_DEBUG_RULE( SetPredicate );
			BOOST_SPIRIT_DEBUG_RULE( SetPredicatePart2 );
			BOOST_SPIRIT_DEBUG_RULE( TypePredicate );
			BOOST_SPIRIT_DEBUG_RULE( TypePredicatePart2 );
			BOOST_SPIRIT_DEBUG_RULE( TypeList );
			BOOST_SPIRIT_DEBUG_RULE( UserDefinedTypeSpecification );
			BOOST_SPIRIT_DEBUG_RULE( InclusiveUserDefinedTypeSpecification );
			BOOST_SPIRIT_DEBUG_RULE( ExclusiveUserDefinedTypeSpecification );
			BOOST_SPIRIT_DEBUG_RULE( SearchCondition );
			BOOST_SPIRIT_DEBUG_RULE( IntervalQualifier );
			BOOST_SPIRIT_DEBUG_RULE( StartField );
			BOOST_SPIRIT_DEBUG_RULE( EndField );
			BOOST_SPIRIT_DEBUG_RULE( SingleDatetimeField );
			BOOST_SPIRIT_DEBUG_RULE( PrimaryDatetimeField );
			BOOST_SPIRIT_DEBUG_RULE( NonSecondPrimaryDatetimeField );
			BOOST_SPIRIT_DEBUG_RULE( IntervalFractionalSecondsPrecision );
			BOOST_SPIRIT_DEBUG_RULE( IntervalLeadingFieldPrecision );
			BOOST_SPIRIT_DEBUG_RULE( LanguageClause );
			BOOST_SPIRIT_DEBUG_RULE( LanguageName );
			BOOST_SPIRIT_DEBUG_RULE( PathSpecification );
			BOOST_SPIRIT_DEBUG_RULE( SchemaNameList );
			BOOST_SPIRIT_DEBUG_RULE( RoutineInvocation );
			BOOST_SPIRIT_DEBUG_RULE( RoutineName );
			BOOST_SPIRIT_DEBUG_RULE( SQLArgumentList );
			BOOST_SPIRIT_DEBUG_RULE( SQLArgument );
			BOOST_SPIRIT_DEBUG_RULE( GeneralizedExpression );
			BOOST_SPIRIT_DEBUG_RULE( CharacterSetSpecification );
			BOOST_SPIRIT_DEBUG_RULE( StandardCharacterSetName );
			BOOST_SPIRIT_DEBUG_RULE( ImplementationDefinedCharacterSetName );
			BOOST_SPIRIT_DEBUG_RULE( UserDefinedCharacterSetName );
			BOOST_SPIRIT_DEBUG_RULE( SpecificRoutineDesignator );
			BOOST_SPIRIT_DEBUG_RULE( RoutineType );
			BOOST_SPIRIT_DEBUG_RULE( MemberName );
			BOOST_SPIRIT_DEBUG_RULE( MemberNameAlternatives );
			BOOST_SPIRIT_DEBUG_RULE( DataTypeList );
			BOOST_SPIRIT_DEBUG_RULE( CollateClause );
			BOOST_SPIRIT_DEBUG_RULE( ConstraintNameDefinition );
			BOOST_SPIRIT_DEBUG_RULE( ConstraintCharacteristics );
			BOOST_SPIRIT_DEBUG_RULE( ConstraintCheckTime );
			BOOST_SPIRIT_DEBUG_RULE( AggregateFunction );
			BOOST_SPIRIT_DEBUG_RULE( GeneralSetFunction );
			BOOST_SPIRIT_DEBUG_RULE( SetFunctionType );
			BOOST_SPIRIT_DEBUG_RULE( ComputationalOperation );
			BOOST_SPIRIT_DEBUG_RULE( SetQuantifier );
			BOOST_SPIRIT_DEBUG_RULE( FilterClause );
			BOOST_SPIRIT_DEBUG_RULE( BinarySetFunction );
			BOOST_SPIRIT_DEBUG_RULE( BinarySetFunctionType );
			BOOST_SPIRIT_DEBUG_RULE( DependentVariableExpression );
			BOOST_SPIRIT_DEBUG_RULE( IndependentVariableExpression );
			BOOST_SPIRIT_DEBUG_RULE( OrderedSetFunction );
			BOOST_SPIRIT_DEBUG_RULE( HypotheticalSetFunction );
			BOOST_SPIRIT_DEBUG_RULE( WithinGroupSpecification );
			BOOST_SPIRIT_DEBUG_RULE( HypotheticalSetFunctionValueExpressionList );
			BOOST_SPIRIT_DEBUG_RULE( InverseDistributionFunction );
			BOOST_SPIRIT_DEBUG_RULE( InverseDistributionFunctionArgument );
			BOOST_SPIRIT_DEBUG_RULE( InverseDistributionFunctionType );
			BOOST_SPIRIT_DEBUG_RULE( SortSpecificationList );
			BOOST_SPIRIT_DEBUG_RULE( SortSpecification );
			BOOST_SPIRIT_DEBUG_RULE( SortKey );
			BOOST_SPIRIT_DEBUG_RULE( OrderingSpecification );
			BOOST_SPIRIT_DEBUG_RULE( NullOrdering );
			BOOST_SPIRIT_DEBUG_RULE( SchemaDefinition );
			BOOST_SPIRIT_DEBUG_RULE( SchemaCharacterSetOrPath );
			BOOST_SPIRIT_DEBUG_RULE( SchemaNameClause );
			BOOST_SPIRIT_DEBUG_RULE( SchemaAuthorizationIdentifier );
			BOOST_SPIRIT_DEBUG_RULE( SchemaCharacterSetSpecification );
			BOOST_SPIRIT_DEBUG_RULE( SchemaPathSpecification );
			BOOST_SPIRIT_DEBUG_RULE( SchemaElement );
			BOOST_SPIRIT_DEBUG_RULE( DropSchemaStatement );
			BOOST_SPIRIT_DEBUG_RULE( DropBehavior );
			BOOST_SPIRIT_DEBUG_RULE( TableDefinition );
			BOOST_SPIRIT_DEBUG_RULE( TableContentsSource );
			BOOST_SPIRIT_DEBUG_RULE( TableScope );
			BOOST_SPIRIT_DEBUG_RULE( GlobalOrLocal );
			BOOST_SPIRIT_DEBUG_RULE( TableCommitAction );
			BOOST_SPIRIT_DEBUG_RULE( TableElementList );
			BOOST_SPIRIT_DEBUG_RULE( TableElement );
			BOOST_SPIRIT_DEBUG_RULE( SelfReferencingColumnSpecification );
			BOOST_SPIRIT_DEBUG_RULE( ReferenceGeneration );
			BOOST_SPIRIT_DEBUG_RULE( SelfReferencingColumnName );
			BOOST_SPIRIT_DEBUG_RULE( ColumnOptions );
			BOOST_SPIRIT_DEBUG_RULE( ColumnOptionList );
			BOOST_SPIRIT_DEBUG_RULE( SubtableClause );
			BOOST_SPIRIT_DEBUG_RULE( SupertableClause );
			BOOST_SPIRIT_DEBUG_RULE( SupertableName );
			BOOST_SPIRIT_DEBUG_RULE( LikeClause );
			BOOST_SPIRIT_DEBUG_RULE( LikeOptions );
			BOOST_SPIRIT_DEBUG_RULE( IdentityOption );
			BOOST_SPIRIT_DEBUG_RULE( ColumnDefaultOption );
			BOOST_SPIRIT_DEBUG_RULE( AsSubqueryClause );
			BOOST_SPIRIT_DEBUG_RULE( WithOrWithoutData );
			BOOST_SPIRIT_DEBUG_RULE( ColumnDefinition );
			BOOST_SPIRIT_DEBUG_RULE( ColumnConstraintDefinition );
			BOOST_SPIRIT_DEBUG_RULE( ColumnConstraint );
			BOOST_SPIRIT_DEBUG_RULE( ReferenceScopeCheck );
			BOOST_SPIRIT_DEBUG_RULE( ReferenceScopeCheckAction );
			BOOST_SPIRIT_DEBUG_RULE( IdentityColumnSpecification );
			BOOST_SPIRIT_DEBUG_RULE( GenerationClause );
			BOOST_SPIRIT_DEBUG_RULE( GenerationRule );
			BOOST_SPIRIT_DEBUG_RULE( GenerationExpression );
			BOOST_SPIRIT_DEBUG_RULE( DefaultClause );
			BOOST_SPIRIT_DEBUG_RULE( DefaultOption );
			BOOST_SPIRIT_DEBUG_RULE( TableConstraintDefinition );
			BOOST_SPIRIT_DEBUG_RULE( TableConstraint );
			BOOST_SPIRIT_DEBUG_RULE( UniqueConstraintDefinition );
			BOOST_SPIRIT_DEBUG_RULE( UniqueSpecification );
			BOOST_SPIRIT_DEBUG_RULE( UniqueColumnList );
			BOOST_SPIRIT_DEBUG_RULE( ReferentialConstraintDefinition );
			BOOST_SPIRIT_DEBUG_RULE( ReferencesSpecification );
			BOOST_SPIRIT_DEBUG_RULE( MatchType );
			BOOST_SPIRIT_DEBUG_RULE( ReferencingColumns );
			BOOST_SPIRIT_DEBUG_RULE( ReferencedTableAndColumns );
			BOOST_SPIRIT_DEBUG_RULE( ReferenceColumnList );
			BOOST_SPIRIT_DEBUG_RULE( ReferentialTriggeredAction );
			BOOST_SPIRIT_DEBUG_RULE( UpdateRule );
			BOOST_SPIRIT_DEBUG_RULE( DeleteRule );
			BOOST_SPIRIT_DEBUG_RULE( ReferentialAction );
			BOOST_SPIRIT_DEBUG_RULE( CheckConstraintDefinition );
			BOOST_SPIRIT_DEBUG_RULE( AlterTableStatement );
			BOOST_SPIRIT_DEBUG_RULE( AlterTableAction );
			BOOST_SPIRIT_DEBUG_RULE( AddColumnDefinition );
			BOOST_SPIRIT_DEBUG_RULE( AlterColumnDefinition );
			BOOST_SPIRIT_DEBUG_RULE( AlterColumnAction );
			BOOST_SPIRIT_DEBUG_RULE( SetColumnDefaultClause );
			BOOST_SPIRIT_DEBUG_RULE( DropColumnDefaultClause );
			BOOST_SPIRIT_DEBUG_RULE( AddColumnScopeClause );
			BOOST_SPIRIT_DEBUG_RULE( DropColumnScopeClause );
			BOOST_SPIRIT_DEBUG_RULE( AlterIdentityColumnSpecification );
			BOOST_SPIRIT_DEBUG_RULE( AlterIdentityColumnOption );
			BOOST_SPIRIT_DEBUG_RULE( DropColumnDefinition );
			BOOST_SPIRIT_DEBUG_RULE( AddTableConstraintDefinition );
			BOOST_SPIRIT_DEBUG_RULE( DropTableConstraintDefinition );
			BOOST_SPIRIT_DEBUG_RULE( DropTableStatement );
			BOOST_SPIRIT_DEBUG_RULE( ViewDefinition );
			BOOST_SPIRIT_DEBUG_RULE( ViewSpecification );
			BOOST_SPIRIT_DEBUG_RULE( RegularViewSpecification );
			BOOST_SPIRIT_DEBUG_RULE( ReferenceableViewSpecification );
			BOOST_SPIRIT_DEBUG_RULE( SubviewClause );
			BOOST_SPIRIT_DEBUG_RULE( ViewElementList );
			BOOST_SPIRIT_DEBUG_RULE( ViewElement );
			BOOST_SPIRIT_DEBUG_RULE( ViewColumnOption );
			BOOST_SPIRIT_DEBUG_RULE( LevelsClause );
			BOOST_SPIRIT_DEBUG_RULE( ViewColumnList );
			BOOST_SPIRIT_DEBUG_RULE( DropViewStatement );
			BOOST_SPIRIT_DEBUG_RULE( DomainDefinition );
			BOOST_SPIRIT_DEBUG_RULE( DomainConstraint );
			BOOST_SPIRIT_DEBUG_RULE( AlterDomainStatement );
			BOOST_SPIRIT_DEBUG_RULE( AlterDomainAction );
			BOOST_SPIRIT_DEBUG_RULE( SetDomainDefaultClause );
			BOOST_SPIRIT_DEBUG_RULE( DropDomainDefaultClause );
			BOOST_SPIRIT_DEBUG_RULE( AddDomainConstraintDefinition );
			BOOST_SPIRIT_DEBUG_RULE( DropDomainConstraintDefinition );
			BOOST_SPIRIT_DEBUG_RULE( DropDomainStatement );
			BOOST_SPIRIT_DEBUG_RULE( CharacterSetDefinition );
			BOOST_SPIRIT_DEBUG_RULE( CharacterSetSource );
			BOOST_SPIRIT_DEBUG_RULE( DropCharacterSetStatement );
			BOOST_SPIRIT_DEBUG_RULE( CollationDefinition );
			BOOST_SPIRIT_DEBUG_RULE( ExistingCollationName );
			BOOST_SPIRIT_DEBUG_RULE( PadCharacteristic );
			BOOST_SPIRIT_DEBUG_RULE( DropCollationStatement );
			BOOST_SPIRIT_DEBUG_RULE( TransliterationDefinition );
			BOOST_SPIRIT_DEBUG_RULE( SourceCharacterSetSpecification );
			BOOST_SPIRIT_DEBUG_RULE( TargetCharacterSetSpecification );
			BOOST_SPIRIT_DEBUG_RULE( TransliterationSource );
			BOOST_SPIRIT_DEBUG_RULE( ExistingTransliterationName );
			BOOST_SPIRIT_DEBUG_RULE( TransliterationRoutine );
			BOOST_SPIRIT_DEBUG_RULE( DropTransliterationStatement );
			BOOST_SPIRIT_DEBUG_RULE( AssertionDefinition );
			BOOST_SPIRIT_DEBUG_RULE( DropAssertionStatement );
			BOOST_SPIRIT_DEBUG_RULE( TriggerDefinition );
			BOOST_SPIRIT_DEBUG_RULE( TriggerActionTime );
			BOOST_SPIRIT_DEBUG_RULE( TriggerEvent );
			BOOST_SPIRIT_DEBUG_RULE( TriggerColumnList );
			BOOST_SPIRIT_DEBUG_RULE( TriggeredAction );
			BOOST_SPIRIT_DEBUG_RULE( TriggeredSQLStatement );
			BOOST_SPIRIT_DEBUG_RULE( OldOrNewValuesAliasList );
			BOOST_SPIRIT_DEBUG_RULE( OldOrNewValuesAlias );
			BOOST_SPIRIT_DEBUG_RULE( OldValuesTableAlias );
			BOOST_SPIRIT_DEBUG_RULE( NewValuesTableAlias );
			BOOST_SPIRIT_DEBUG_RULE( OldValuesCorrelationName );
			BOOST_SPIRIT_DEBUG_RULE( NewValuesCorrelationName );
			BOOST_SPIRIT_DEBUG_RULE( DropTriggerStatement );
			BOOST_SPIRIT_DEBUG_RULE( UserDefinedTypeDefinition );
			BOOST_SPIRIT_DEBUG_RULE( UserDefinedTypeBody );
			BOOST_SPIRIT_DEBUG_RULE( UserDefinedTypeOptionList );
			BOOST_SPIRIT_DEBUG_RULE( UserDefinedTypeOption );
			BOOST_SPIRIT_DEBUG_RULE( SubtypeClause );
			BOOST_SPIRIT_DEBUG_RULE( SupertypeName );
			BOOST_SPIRIT_DEBUG_RULE( Representation );
			BOOST_SPIRIT_DEBUG_RULE( MemberList );
			BOOST_SPIRIT_DEBUG_RULE( Member );
			BOOST_SPIRIT_DEBUG_RULE( InstantiableClause );
			BOOST_SPIRIT_DEBUG_RULE( Finality );
			BOOST_SPIRIT_DEBUG_RULE( ReferenceTypeSpecification );
			BOOST_SPIRIT_DEBUG_RULE( UserDefinedRepresentation );
			BOOST_SPIRIT_DEBUG_RULE( DerivedRepresentation );
			BOOST_SPIRIT_DEBUG_RULE( SystemGeneratedRepresentation );
			BOOST_SPIRIT_DEBUG_RULE( RefCastOption );
			BOOST_SPIRIT_DEBUG_RULE( CastToRef );
			BOOST_SPIRIT_DEBUG_RULE( CastToRefIdentifier );
			BOOST_SPIRIT_DEBUG_RULE( CastToType );
			BOOST_SPIRIT_DEBUG_RULE( CastToTypeIdentifier );
			BOOST_SPIRIT_DEBUG_RULE( ListOfAttributes );
			BOOST_SPIRIT_DEBUG_RULE( CastOption );
			BOOST_SPIRIT_DEBUG_RULE( CastToDistinct );
			BOOST_SPIRIT_DEBUG_RULE( CastToDistinctIdentifier );
			BOOST_SPIRIT_DEBUG_RULE( CastToSource );
			BOOST_SPIRIT_DEBUG_RULE( CastToSourceIdentifier );
			BOOST_SPIRIT_DEBUG_RULE( MethodSpecificationList );
			BOOST_SPIRIT_DEBUG_RULE( MethodSpecification );
			BOOST_SPIRIT_DEBUG_RULE( OriginalMethodSpecification );
			BOOST_SPIRIT_DEBUG_RULE( OverridingMethodSpecification );
			BOOST_SPIRIT_DEBUG_RULE( PartialMethodSpecification );
			BOOST_SPIRIT_DEBUG_RULE( SpecificMethodName );
			BOOST_SPIRIT_DEBUG_RULE( MethodCharacteristics );
			BOOST_SPIRIT_DEBUG_RULE( MethodCharacteristic );
			BOOST_SPIRIT_DEBUG_RULE( AttributeDefinition );
			BOOST_SPIRIT_DEBUG_RULE( AttributeDefault );
			BOOST_SPIRIT_DEBUG_RULE( AlterTypeStatement );
			BOOST_SPIRIT_DEBUG_RULE( AlterTypeAction );
			BOOST_SPIRIT_DEBUG_RULE( AddAttributeDefinition );
			BOOST_SPIRIT_DEBUG_RULE( DropAttributeDefinition );
			BOOST_SPIRIT_DEBUG_RULE( AddOriginalMethodSpecification );
			BOOST_SPIRIT_DEBUG_RULE( AddOverridingMethodSpecification );
			BOOST_SPIRIT_DEBUG_RULE( DropMethodSpecification );
			BOOST_SPIRIT_DEBUG_RULE( SpecificMethodSpecificationDesignator );
			BOOST_SPIRIT_DEBUG_RULE( DropDataTypeStatement );
			BOOST_SPIRIT_DEBUG_RULE( SQLInvokedRoutine );
			BOOST_SPIRIT_DEBUG_RULE( SchemaRoutine );
			BOOST_SPIRIT_DEBUG_RULE( SchemaProcedure );
			BOOST_SPIRIT_DEBUG_RULE( SchemaFunction );
			BOOST_SPIRIT_DEBUG_RULE( SQLInvokedProcedure );
			BOOST_SPIRIT_DEBUG_RULE( SQLInvokedFunction );
			BOOST_SPIRIT_DEBUG_RULE( SQLParameterDeclarationList );
			BOOST_SPIRIT_DEBUG_RULE( SQLParameterDeclaration );
			BOOST_SPIRIT_DEBUG_RULE( ParameterMode );
			BOOST_SPIRIT_DEBUG_RULE( ParameterType );
			BOOST_SPIRIT_DEBUG_RULE( LocatorIndication );
			BOOST_SPIRIT_DEBUG_RULE( FunctionSpecification );
			BOOST_SPIRIT_DEBUG_RULE( MethodSpecificationDesignator );
			BOOST_SPIRIT_DEBUG_RULE( RoutineCharacteristics );
			BOOST_SPIRIT_DEBUG_RULE( RoutineCharacteristic );
			BOOST_SPIRIT_DEBUG_RULE( SavepointLevelIndication );
			BOOST_SPIRIT_DEBUG_RULE( DynamicResultSetsCharacteristic );
			BOOST_SPIRIT_DEBUG_RULE( ParameterStyleClause );
			BOOST_SPIRIT_DEBUG_RULE( DispatchClause );
			BOOST_SPIRIT_DEBUG_RULE( ReturnsClause );
			BOOST_SPIRIT_DEBUG_RULE( ReturnsType );
			BOOST_SPIRIT_DEBUG_RULE( ReturnsTableType );
			BOOST_SPIRIT_DEBUG_RULE( TableFunctionColumnList );
			BOOST_SPIRIT_DEBUG_RULE( TableFunctionColumnListElement );
			BOOST_SPIRIT_DEBUG_RULE( ResultCast );
			BOOST_SPIRIT_DEBUG_RULE( ResultCastFromType );
			BOOST_SPIRIT_DEBUG_RULE( ReturnsDataType );
			BOOST_SPIRIT_DEBUG_RULE( RoutineBody );
			BOOST_SPIRIT_DEBUG_RULE( SQLRoutineSpec );
			BOOST_SPIRIT_DEBUG_RULE( RightsClause );
			BOOST_SPIRIT_DEBUG_RULE( SQLRoutineBody );
			BOOST_SPIRIT_DEBUG_RULE( ExternalBodyReference );
			BOOST_SPIRIT_DEBUG_RULE( ExternalSecurityClause );
			BOOST_SPIRIT_DEBUG_RULE( ParameterStyle );
			BOOST_SPIRIT_DEBUG_RULE( DeterministicCharacteristic );
			BOOST_SPIRIT_DEBUG_RULE( SQLDataAccessIndication );
			BOOST_SPIRIT_DEBUG_RULE( NullCallClause );
			BOOST_SPIRIT_DEBUG_RULE( MaximumDynamicResultSets );
			BOOST_SPIRIT_DEBUG_RULE( TransformGroupSpecification );
			BOOST_SPIRIT_DEBUG_RULE( SingleGroupSpecification );
			BOOST_SPIRIT_DEBUG_RULE( MultipleGroupSpecification );
			BOOST_SPIRIT_DEBUG_RULE( GroupSpecification );
			BOOST_SPIRIT_DEBUG_RULE( AlterRoutineStatement );
			BOOST_SPIRIT_DEBUG_RULE( AlterRoutineCharacteristics );
			BOOST_SPIRIT_DEBUG_RULE( AlterRoutineCharacteristic );
			BOOST_SPIRIT_DEBUG_RULE( AlterRoutineBehavior );
			BOOST_SPIRIT_DEBUG_RULE( DropRoutineStatement );
			BOOST_SPIRIT_DEBUG_RULE( UserDefinedCastDefinition );
			BOOST_SPIRIT_DEBUG_RULE( CastFunction );
			BOOST_SPIRIT_DEBUG_RULE( SourceDataType );
			BOOST_SPIRIT_DEBUG_RULE( TargetDataType );
			BOOST_SPIRIT_DEBUG_RULE( DropUserDefinedCastStatement );
			BOOST_SPIRIT_DEBUG_RULE( UserDefinedOrderingDefinition );
			BOOST_SPIRIT_DEBUG_RULE( OrderingForm );
			BOOST_SPIRIT_DEBUG_RULE( EqualsOrderingForm );
			BOOST_SPIRIT_DEBUG_RULE( FullOrderingForm );
			BOOST_SPIRIT_DEBUG_RULE( OrderingCategory );
			BOOST_SPIRIT_DEBUG_RULE( RelativeCategory );
			BOOST_SPIRIT_DEBUG_RULE( MapCategory );
			BOOST_SPIRIT_DEBUG_RULE( StateCategory );
			BOOST_SPIRIT_DEBUG_RULE( RelativeFunctionSpecification );
			BOOST_SPIRIT_DEBUG_RULE( MapFunctionSpecification );
			BOOST_SPIRIT_DEBUG_RULE( DropUserDefinedOrderingStatement );
			BOOST_SPIRIT_DEBUG_RULE( TransformDefinition );
			BOOST_SPIRIT_DEBUG_RULE( TransformGroup );
			BOOST_SPIRIT_DEBUG_RULE( GroupName );
			BOOST_SPIRIT_DEBUG_RULE( TransformElementList );
			BOOST_SPIRIT_DEBUG_RULE( TransformElement );
			BOOST_SPIRIT_DEBUG_RULE( ToSql );
			BOOST_SPIRIT_DEBUG_RULE( FromSql );
			BOOST_SPIRIT_DEBUG_RULE( ToSqlFunction );
			BOOST_SPIRIT_DEBUG_RULE( FromSqlFunction );
			BOOST_SPIRIT_DEBUG_RULE( AlterTransformStatement );
			BOOST_SPIRIT_DEBUG_RULE( AlterGroup );
			BOOST_SPIRIT_DEBUG_RULE( AlterTransformActionList );
			BOOST_SPIRIT_DEBUG_RULE( AlterTransformAction );
			BOOST_SPIRIT_DEBUG_RULE( AddTransformElementList );
			BOOST_SPIRIT_DEBUG_RULE( DropTransformElementList );
			BOOST_SPIRIT_DEBUG_RULE( TransformKind );
			BOOST_SPIRIT_DEBUG_RULE( DropTransformStatement );
			BOOST_SPIRIT_DEBUG_RULE( TransformsToBeDropped );
			BOOST_SPIRIT_DEBUG_RULE( TransformGroupElement );
			BOOST_SPIRIT_DEBUG_RULE( SequenceGeneratorDefinition );
			BOOST_SPIRIT_DEBUG_RULE( SequenceGeneratorOptions );
			BOOST_SPIRIT_DEBUG_RULE( SequenceGeneratorOption );
			BOOST_SPIRIT_DEBUG_RULE( CommonSequenceGeneratorOptions );
			BOOST_SPIRIT_DEBUG_RULE( CommonSequenceGeneratorOption );
			BOOST_SPIRIT_DEBUG_RULE( BasicSequenceGeneratorOption );
			BOOST_SPIRIT_DEBUG_RULE( SequenceGeneratorDataTypeOption );
			BOOST_SPIRIT_DEBUG_RULE( SequenceGeneratorStartWithOption );
			BOOST_SPIRIT_DEBUG_RULE( SequenceGeneratorStartValue );
			BOOST_SPIRIT_DEBUG_RULE( SequenceGeneratorIncrementByOption );
			BOOST_SPIRIT_DEBUG_RULE( SequenceGeneratorIncrement );
			BOOST_SPIRIT_DEBUG_RULE( SequenceGeneratorMaxvalueOption );
			BOOST_SPIRIT_DEBUG_RULE( SequenceGeneratorMaxValue );
			BOOST_SPIRIT_DEBUG_RULE( SequenceGeneratorMinvalueOption );
			BOOST_SPIRIT_DEBUG_RULE( SequenceGeneratorMinValue );
			BOOST_SPIRIT_DEBUG_RULE( SequenceGeneratorCycleOption );
			BOOST_SPIRIT_DEBUG_RULE( AlterSequenceGeneratorStatement );
			BOOST_SPIRIT_DEBUG_RULE( AlterSequenceGeneratorOptions );
			BOOST_SPIRIT_DEBUG_RULE( AlterSequenceGeneratorOption );
			BOOST_SPIRIT_DEBUG_RULE( AlterSequenceGeneratorRestartOption );
			BOOST_SPIRIT_DEBUG_RULE( SequenceGeneratorRestartValue );
			BOOST_SPIRIT_DEBUG_RULE( DropSequenceGeneratorStatement );
			BOOST_SPIRIT_DEBUG_RULE( GrantStatement );
			BOOST_SPIRIT_DEBUG_RULE( GrantPrivilegeStatement );
			BOOST_SPIRIT_DEBUG_RULE( Privileges );
			BOOST_SPIRIT_DEBUG_RULE( ObjectName );
			BOOST_SPIRIT_DEBUG_RULE( ObjectPrivileges );
			BOOST_SPIRIT_DEBUG_RULE( Action );
			BOOST_SPIRIT_DEBUG_RULE( PrivilegeMethodList );
			BOOST_SPIRIT_DEBUG_RULE( PrivilegeColumnList );
			BOOST_SPIRIT_DEBUG_RULE( Grantee );
			BOOST_SPIRIT_DEBUG_RULE( Grantor );
			BOOST_SPIRIT_DEBUG_RULE( RoleDefinition );
			BOOST_SPIRIT_DEBUG_RULE( GrantRoleStatement );
			BOOST_SPIRIT_DEBUG_RULE( RoleGranted );
			BOOST_SPIRIT_DEBUG_RULE( DropRoleStatement );
			BOOST_SPIRIT_DEBUG_RULE( RevokeStatement );
			BOOST_SPIRIT_DEBUG_RULE( RevokePrivilegeStatement );
			BOOST_SPIRIT_DEBUG_RULE( RevokeOptionExtension );
			BOOST_SPIRIT_DEBUG_RULE( RevokeRoleStatement );
			BOOST_SPIRIT_DEBUG_RULE( RoleRevoked );
			BOOST_SPIRIT_DEBUG_RULE( SQLClientModuleDefinition );
			BOOST_SPIRIT_DEBUG_RULE( ModuleAuthorizationClause );
			BOOST_SPIRIT_DEBUG_RULE( ModuleAuthorizationIdentifier );
			BOOST_SPIRIT_DEBUG_RULE( ModulePathSpecification );
			BOOST_SPIRIT_DEBUG_RULE( ModuleTransformGroupSpecification );
			BOOST_SPIRIT_DEBUG_RULE( ModuleCollations );
			BOOST_SPIRIT_DEBUG_RULE( ModuleCollationSpecification );
			BOOST_SPIRIT_DEBUG_RULE( CharacterSetSpecificationList );
			BOOST_SPIRIT_DEBUG_RULE( ModuleContents );
			BOOST_SPIRIT_DEBUG_RULE( ModuleNameClause );
			BOOST_SPIRIT_DEBUG_RULE( ModuleCharacterSetSpecification );
			BOOST_SPIRIT_DEBUG_RULE( ExternallyInvokedProcedure );
			BOOST_SPIRIT_DEBUG_RULE( HostParameterDeclarationList );
			BOOST_SPIRIT_DEBUG_RULE( HostParameterDeclaration );
			BOOST_SPIRIT_DEBUG_RULE( HostParameterDataType );
			BOOST_SPIRIT_DEBUG_RULE( StatusParameter );
			BOOST_SPIRIT_DEBUG_RULE( SQLProcedureStatement );
			BOOST_SPIRIT_DEBUG_RULE( SQLExecutableStatement );
			BOOST_SPIRIT_DEBUG_RULE( SQLSchemaStatement );
			BOOST_SPIRIT_DEBUG_RULE( SQLSchemaDefinitionStatement );
			BOOST_SPIRIT_DEBUG_RULE( SQLSchemaManipulationStatement );
			BOOST_SPIRIT_DEBUG_RULE( SQLDataStatement );
			BOOST_SPIRIT_DEBUG_RULE( SQLDataChangeStatement );
			BOOST_SPIRIT_DEBUG_RULE( SQLControlStatement );
			BOOST_SPIRIT_DEBUG_RULE( SQLTransactionStatement );
			BOOST_SPIRIT_DEBUG_RULE( SQLConnectionStatement );
			BOOST_SPIRIT_DEBUG_RULE( SQLSessionStatement );
			BOOST_SPIRIT_DEBUG_RULE( SQLDiagnosticsStatement );
			BOOST_SPIRIT_DEBUG_RULE( SQLDynamicStatement );
			BOOST_SPIRIT_DEBUG_RULE( SQLDynamicDataStatement );
			BOOST_SPIRIT_DEBUG_RULE( SystemDescriptorStatement );
			BOOST_SPIRIT_DEBUG_RULE( DeclareCursor );
			BOOST_SPIRIT_DEBUG_RULE( CursorSensitivity );
			BOOST_SPIRIT_DEBUG_RULE( CursorScrollability );
			BOOST_SPIRIT_DEBUG_RULE( CursorHoldability );
			BOOST_SPIRIT_DEBUG_RULE( CursorReturnability );
			BOOST_SPIRIT_DEBUG_RULE( CursorSpecification );
			BOOST_SPIRIT_DEBUG_RULE( UpdatabilityClause );
			BOOST_SPIRIT_DEBUG_RULE( OrderByClause );
			BOOST_SPIRIT_DEBUG_RULE( OpenStatement );
			BOOST_SPIRIT_DEBUG_RULE( FetchStatement );
			BOOST_SPIRIT_DEBUG_RULE( FetchOrientation );
			BOOST_SPIRIT_DEBUG_RULE( FetchTargetList );
			BOOST_SPIRIT_DEBUG_RULE( CloseStatement );
			BOOST_SPIRIT_DEBUG_RULE( SelectStatementSingleRow );
			BOOST_SPIRIT_DEBUG_RULE( SelectTargetList );
			BOOST_SPIRIT_DEBUG_RULE( DeleteStatementPositioned );
			BOOST_SPIRIT_DEBUG_RULE( TargetTable );
			BOOST_SPIRIT_DEBUG_RULE( DeleteStatementSearched );
			BOOST_SPIRIT_DEBUG_RULE( InsertStatement );
			BOOST_SPIRIT_DEBUG_RULE( InsertionTarget );
			BOOST_SPIRIT_DEBUG_RULE( InsertColumnsAndSource );
			BOOST_SPIRIT_DEBUG_RULE( FromSubquery );
			BOOST_SPIRIT_DEBUG_RULE( FromConstructor );
			BOOST_SPIRIT_DEBUG_RULE( OverrideClause );
			BOOST_SPIRIT_DEBUG_RULE( FromDefault );
			BOOST_SPIRIT_DEBUG_RULE( InsertColumnList );
			BOOST_SPIRIT_DEBUG_RULE( MergeStatement );
			BOOST_SPIRIT_DEBUG_RULE( MergeCorrelationName );
			BOOST_SPIRIT_DEBUG_RULE( MergeOperationSpecification );
			BOOST_SPIRIT_DEBUG_RULE( MergeWhenClause );
			BOOST_SPIRIT_DEBUG_RULE( MergeWhenMatchedClause );
			BOOST_SPIRIT_DEBUG_RULE( MergeWhenNotMatchedClause );
			BOOST_SPIRIT_DEBUG_RULE( MergeUpdateSpecification );
			BOOST_SPIRIT_DEBUG_RULE( MergeInsertSpecification );
			BOOST_SPIRIT_DEBUG_RULE( MergeInsertValueList );
			BOOST_SPIRIT_DEBUG_RULE( MergeInsertValueElement );
			BOOST_SPIRIT_DEBUG_RULE( UpdateStatementPositioned );
			BOOST_SPIRIT_DEBUG_RULE( UpdateStatementSearched );
			BOOST_SPIRIT_DEBUG_RULE( SetClauseList );
			BOOST_SPIRIT_DEBUG_RULE( SetClause );
			BOOST_SPIRIT_DEBUG_RULE( SetTarget );
			BOOST_SPIRIT_DEBUG_RULE( MultipleColumnAssignment );
			BOOST_SPIRIT_DEBUG_RULE( SetTargetList );
			BOOST_SPIRIT_DEBUG_RULE( AssignedRow );
			BOOST_SPIRIT_DEBUG_RULE( UpdateTarget );
			BOOST_SPIRIT_DEBUG_RULE( ObjectColumn );
			BOOST_SPIRIT_DEBUG_RULE( MutatedSetClause );
			BOOST_SPIRIT_DEBUG_RULE( MutatedTarget );
			BOOST_SPIRIT_DEBUG_RULE( UpdateSource );
			BOOST_SPIRIT_DEBUG_RULE( TemporaryTableDeclaration );
			BOOST_SPIRIT_DEBUG_RULE( FreeLocatorStatement );
			BOOST_SPIRIT_DEBUG_RULE( LocatorReference );
			BOOST_SPIRIT_DEBUG_RULE( HoldLocatorStatement );
			BOOST_SPIRIT_DEBUG_RULE( CallStatement );
			BOOST_SPIRIT_DEBUG_RULE( ReturnStatement );
			BOOST_SPIRIT_DEBUG_RULE( ReturnValue );
			BOOST_SPIRIT_DEBUG_RULE( StartTransactionStatement );
			BOOST_SPIRIT_DEBUG_RULE( TransactionMode );
			BOOST_SPIRIT_DEBUG_RULE( TransactionAccessMode );
			BOOST_SPIRIT_DEBUG_RULE( IsolationLevel );
			BOOST_SPIRIT_DEBUG_RULE( LevelOfIsolation );
			BOOST_SPIRIT_DEBUG_RULE( DiagnosticsSize );
			BOOST_SPIRIT_DEBUG_RULE( NumberOfConditions );
			BOOST_SPIRIT_DEBUG_RULE( SetTransactionStatement );
			BOOST_SPIRIT_DEBUG_RULE( TransactionCharacteristics );
			BOOST_SPIRIT_DEBUG_RULE( SetConstraintsModeStatement );
			BOOST_SPIRIT_DEBUG_RULE( ConstraintNameList );
			BOOST_SPIRIT_DEBUG_RULE( SavepointStatement );
			BOOST_SPIRIT_DEBUG_RULE( SavepointSpecifier );
			BOOST_SPIRIT_DEBUG_RULE( ReleaseSavepointStatement );
			BOOST_SPIRIT_DEBUG_RULE( CommitStatement );
			BOOST_SPIRIT_DEBUG_RULE( RollbackStatement );
			BOOST_SPIRIT_DEBUG_RULE( SavepointClause );
			BOOST_SPIRIT_DEBUG_RULE( ConnectStatement );
			BOOST_SPIRIT_DEBUG_RULE( ConnectionTarget );
			BOOST_SPIRIT_DEBUG_RULE( SetConnectionStatement );
			BOOST_SPIRIT_DEBUG_RULE( ConnectionObject );
			BOOST_SPIRIT_DEBUG_RULE( DisconnectStatement );
			BOOST_SPIRIT_DEBUG_RULE( DisconnectObject );
			BOOST_SPIRIT_DEBUG_RULE( SetSessionCharacteristicsStatement );
			BOOST_SPIRIT_DEBUG_RULE( SessionCharacteristicList );
			BOOST_SPIRIT_DEBUG_RULE( SessionCharacteristic );
			BOOST_SPIRIT_DEBUG_RULE( SetSessionUserIdentifierStatement );
			BOOST_SPIRIT_DEBUG_RULE( SetRoleStatement );
			BOOST_SPIRIT_DEBUG_RULE( RoleSpecification );
			BOOST_SPIRIT_DEBUG_RULE( SetLocalTimeZoneStatement );
			BOOST_SPIRIT_DEBUG_RULE( SetTimeZoneValue );
			BOOST_SPIRIT_DEBUG_RULE( SetCatalogStatement );
			BOOST_SPIRIT_DEBUG_RULE( CatalogNameCharacteristic );
			BOOST_SPIRIT_DEBUG_RULE( SetSchemaStatement );
			BOOST_SPIRIT_DEBUG_RULE( SchemaNameCharacteristic );
			BOOST_SPIRIT_DEBUG_RULE( SetNamesStatement );
			BOOST_SPIRIT_DEBUG_RULE( CharacterSetNameCharacteristic );
			BOOST_SPIRIT_DEBUG_RULE( SetPathStatement );
			BOOST_SPIRIT_DEBUG_RULE( SQLPathCharacteristic );
			BOOST_SPIRIT_DEBUG_RULE( SetTransformGroupStatement );
			BOOST_SPIRIT_DEBUG_RULE( TransformGroupCharacteristic );
			BOOST_SPIRIT_DEBUG_RULE( SetSessionCollationStatement );
			BOOST_SPIRIT_DEBUG_RULE( CharacterSetSpecificationList );
			BOOST_SPIRIT_DEBUG_RULE( CollationSpecification );
			BOOST_SPIRIT_DEBUG_RULE( AllocateDescriptorStatement );
			BOOST_SPIRIT_DEBUG_RULE( Occurrences );
			BOOST_SPIRIT_DEBUG_RULE( DeallocateDescriptorStatement );
			BOOST_SPIRIT_DEBUG_RULE( GetDescriptorStatement );
			BOOST_SPIRIT_DEBUG_RULE( GetDescriptorInformation );
			BOOST_SPIRIT_DEBUG_RULE( GetHeaderInformation );
			BOOST_SPIRIT_DEBUG_RULE( HeaderItemName );
			BOOST_SPIRIT_DEBUG_RULE( GetItemInformation );
			BOOST_SPIRIT_DEBUG_RULE( ItemNumber );
			BOOST_SPIRIT_DEBUG_RULE( SimpleTargetSpecification1 );
			BOOST_SPIRIT_DEBUG_RULE( SimpleTargetSpecification2 );
			BOOST_SPIRIT_DEBUG_RULE( DescriptorItemName );
			BOOST_SPIRIT_DEBUG_RULE( SetDescriptorStatement );
			BOOST_SPIRIT_DEBUG_RULE( SetDescriptorInformation );
			BOOST_SPIRIT_DEBUG_RULE( SetHeaderInformation );
			BOOST_SPIRIT_DEBUG_RULE( SetItemInformation );
			BOOST_SPIRIT_DEBUG_RULE( SimpleValueSpecification1 );
			BOOST_SPIRIT_DEBUG_RULE( SimpleValueSpecification2 );
			BOOST_SPIRIT_DEBUG_RULE( ItemNumber );
			BOOST_SPIRIT_DEBUG_RULE( PrepareStatement );
			BOOST_SPIRIT_DEBUG_RULE( AttributesSpecification );
			BOOST_SPIRIT_DEBUG_RULE( AttributesVariable );
			BOOST_SPIRIT_DEBUG_RULE( SQLStatementVariable );
			BOOST_SPIRIT_DEBUG_RULE( PreparableStatement );
			BOOST_SPIRIT_DEBUG_RULE( PreparableSQLDataStatement );
			BOOST_SPIRIT_DEBUG_RULE( PreparableSQLSchemaStatement );
			BOOST_SPIRIT_DEBUG_RULE( PreparableSQLTransactionStatement );
			BOOST_SPIRIT_DEBUG_RULE( PreparableSQLControlStatement );
			BOOST_SPIRIT_DEBUG_RULE( PreparableSQLSessionStatement );
			BOOST_SPIRIT_DEBUG_RULE( DynamicSelectStatement );
			BOOST_SPIRIT_DEBUG_RULE( PreparableImplementationDefinedStatement );
			BOOST_SPIRIT_DEBUG_RULE( CursorAttributes );
			BOOST_SPIRIT_DEBUG_RULE( CursorAttribute );
			BOOST_SPIRIT_DEBUG_RULE( DeallocatePreparedStatement );
			BOOST_SPIRIT_DEBUG_RULE( DescribeStatement );
			BOOST_SPIRIT_DEBUG_RULE( DescribeInputStatement );
			BOOST_SPIRIT_DEBUG_RULE( DescribeOutputStatement );
			BOOST_SPIRIT_DEBUG_RULE( NestingOption );
			BOOST_SPIRIT_DEBUG_RULE( UsingDescriptor );
			BOOST_SPIRIT_DEBUG_RULE( DescribedObject );
			BOOST_SPIRIT_DEBUG_RULE( InputUsingClause );
			BOOST_SPIRIT_DEBUG_RULE( UsingArguments );
			BOOST_SPIRIT_DEBUG_RULE( UsingArgument );
			BOOST_SPIRIT_DEBUG_RULE( UsingInputDescriptor );
			BOOST_SPIRIT_DEBUG_RULE( OutputUsingClause );
			BOOST_SPIRIT_DEBUG_RULE( IntoArguments );
			BOOST_SPIRIT_DEBUG_RULE( IntoArgument );
			BOOST_SPIRIT_DEBUG_RULE( IntoDescriptor );
			BOOST_SPIRIT_DEBUG_RULE( ExecuteStatement );
			BOOST_SPIRIT_DEBUG_RULE( ResultUsingClause );
			BOOST_SPIRIT_DEBUG_RULE( ParameterUsingClause );
			BOOST_SPIRIT_DEBUG_RULE( ExecuteImmediateStatement );
			BOOST_SPIRIT_DEBUG_RULE( DynamicDeclareCursor );
			BOOST_SPIRIT_DEBUG_RULE( AllocateCursorStatement );
			BOOST_SPIRIT_DEBUG_RULE( CursorIntent );
			BOOST_SPIRIT_DEBUG_RULE( StatementCursor );
			BOOST_SPIRIT_DEBUG_RULE( ResultSetCursor );
			BOOST_SPIRIT_DEBUG_RULE( DynamicOpenStatement );
			BOOST_SPIRIT_DEBUG_RULE( DynamicFetchStatement );
			BOOST_SPIRIT_DEBUG_RULE( DynamicSingleRowSelectStatement );
			BOOST_SPIRIT_DEBUG_RULE( DynamicCloseStatement );
			BOOST_SPIRIT_DEBUG_RULE( DynamicDeleteStatementPositioned );
			BOOST_SPIRIT_DEBUG_RULE( DynamicUpdateStatementPositioned );
			BOOST_SPIRIT_DEBUG_RULE( PreparableDynamicDeleteStatementPositioned );
			BOOST_SPIRIT_DEBUG_RULE( PreparableDynamicUpdateStatementPositioned );
			BOOST_SPIRIT_DEBUG_RULE( EmbeddedSQLHostProgram );
			BOOST_SPIRIT_DEBUG_RULE( EmbeddedSQLStatement );
			BOOST_SPIRIT_DEBUG_RULE( StatementOrDeclaration );
			BOOST_SPIRIT_DEBUG_RULE( SQLPrefix );
			BOOST_SPIRIT_DEBUG_RULE( SQLTerminator );
			BOOST_SPIRIT_DEBUG_RULE( EmbeddedAuthorizationDeclaration );
			BOOST_SPIRIT_DEBUG_RULE( EmbeddedAuthorizationClause );
			BOOST_SPIRIT_DEBUG_RULE( EmbeddedAuthorizationIdentifier );
			BOOST_SPIRIT_DEBUG_RULE( EmbeddedPathSpecification );
			BOOST_SPIRIT_DEBUG_RULE( EmbeddedTransformGroupSpecification );
			BOOST_SPIRIT_DEBUG_RULE( EmbeddedCollationSpecification );
			BOOST_SPIRIT_DEBUG_RULE( EmbeddedSQLDeclareSection );
			BOOST_SPIRIT_DEBUG_RULE( EmbeddedCharacterSetDeclaration );
			BOOST_SPIRIT_DEBUG_RULE( EmbeddedSQLBeginDeclare );
			BOOST_SPIRIT_DEBUG_RULE( EmbeddedSQLEndDeclare );
			BOOST_SPIRIT_DEBUG_RULE( EmbeddedSQLMUMPSDeclare );
			BOOST_SPIRIT_DEBUG_RULE( HostVariableDefinition );
			BOOST_SPIRIT_DEBUG_RULE( EmbeddedVariableName );
			BOOST_SPIRIT_DEBUG_RULE( HostIdentifier );
			BOOST_SPIRIT_DEBUG_RULE( EmbeddedExceptionDeclaration );
			BOOST_SPIRIT_DEBUG_RULE( Condition );
			BOOST_SPIRIT_DEBUG_RULE( SQLCondition );
			BOOST_SPIRIT_DEBUG_RULE( MajorCategory );
			BOOST_SPIRIT_DEBUG_RULE( SQLSTATEClassValue );
			BOOST_SPIRIT_DEBUG_RULE( SQLSTATESubclassValue );
			BOOST_SPIRIT_DEBUG_RULE( SQLSTATEChar );
			BOOST_SPIRIT_DEBUG_RULE( ConditionAction );
			BOOST_SPIRIT_DEBUG_RULE( GoTo );
			BOOST_SPIRIT_DEBUG_RULE( GotoTarget );
			BOOST_SPIRIT_DEBUG_RULE( HostLabelIdentifier );
			BOOST_SPIRIT_DEBUG_RULE( HostPLILabelVariable );
			BOOST_SPIRIT_DEBUG_RULE( EmbeddedSQLAdaProgram );
			BOOST_SPIRIT_DEBUG_RULE( AdaVariableDefinition );
			BOOST_SPIRIT_DEBUG_RULE( AdaInitialValue );
			BOOST_SPIRIT_DEBUG_RULE( AdaAssignmentOperator );
			BOOST_SPIRIT_DEBUG_RULE( AdaHostIdentifier );
			BOOST_SPIRIT_DEBUG_RULE( AdaTypeSpecification );
			BOOST_SPIRIT_DEBUG_RULE( AdaQualifiedTypeSpecification );
			BOOST_SPIRIT_DEBUG_RULE( AdaUnqualifiedTypeSpecification );
			BOOST_SPIRIT_DEBUG_RULE( AdaDerivedTypeSpecification );
			BOOST_SPIRIT_DEBUG_RULE( AdaCLOBVariable );
			BOOST_SPIRIT_DEBUG_RULE( AdaCLOBLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( AdaBLOBVariable );
			BOOST_SPIRIT_DEBUG_RULE( AdaBLOBLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( AdaUserDefinedTypeVariable );
			BOOST_SPIRIT_DEBUG_RULE( AdaUserDefinedTypeLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( AdaREFVariable );
			BOOST_SPIRIT_DEBUG_RULE( AdaArrayLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( AdaMultisetLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( EmbeddedSQLCProgram );
			BOOST_SPIRIT_DEBUG_RULE( CVariableDefinition );
			BOOST_SPIRIT_DEBUG_RULE( CVariableSpecification );
			BOOST_SPIRIT_DEBUG_RULE( CStorageClass );
			BOOST_SPIRIT_DEBUG_RULE( CClassModifier );
			BOOST_SPIRIT_DEBUG_RULE( CNumericVariable );
			BOOST_SPIRIT_DEBUG_RULE( CCharacterVariable );
			BOOST_SPIRIT_DEBUG_RULE( CCharacterType );
			BOOST_SPIRIT_DEBUG_RULE( CArraySpecification );
			BOOST_SPIRIT_DEBUG_RULE( CHostIdentifier );
			BOOST_SPIRIT_DEBUG_RULE( CDerivedVariable );
			BOOST_SPIRIT_DEBUG_RULE( CVARCHARVariable );
			BOOST_SPIRIT_DEBUG_RULE( CNCHARVariable );
			BOOST_SPIRIT_DEBUG_RULE( CNCHARVARYINGVariable );
			BOOST_SPIRIT_DEBUG_RULE( CCLOBVariable );
			BOOST_SPIRIT_DEBUG_RULE( CNCLOBVariable );
			BOOST_SPIRIT_DEBUG_RULE( CUserDefinedTypeVariable );
			BOOST_SPIRIT_DEBUG_RULE( CBLOBVariable );
			BOOST_SPIRIT_DEBUG_RULE( CCLOBLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( CBLOBLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( CArrayLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( CMultisetLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( CUserDefinedTypeLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( CREFVariable );
			BOOST_SPIRIT_DEBUG_RULE( CInitialValue );
			BOOST_SPIRIT_DEBUG_RULE( EmbeddedSQLCOBOLProgram );
			BOOST_SPIRIT_DEBUG_RULE( COBOLVariableDefinition );
			BOOST_SPIRIT_DEBUG_RULE( COBOLHostIdentifier );
			BOOST_SPIRIT_DEBUG_RULE( COBOLTypeSpecification );
			BOOST_SPIRIT_DEBUG_RULE( COBOLDerivedTypeSpecification );
			BOOST_SPIRIT_DEBUG_RULE( COBOLCharacterType );
			BOOST_SPIRIT_DEBUG_RULE( COBOLNationalCharacterType );
			BOOST_SPIRIT_DEBUG_RULE( COBOLCLOBVariable );
			BOOST_SPIRIT_DEBUG_RULE( COBOLNCLOBVariable );
			BOOST_SPIRIT_DEBUG_RULE( COBOLBLOBVariable );
			BOOST_SPIRIT_DEBUG_RULE( COBOLUserDefinedTypeVariable );
			BOOST_SPIRIT_DEBUG_RULE( COBOLCLOBLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( COBOLBLOBLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( COBOLArrayLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( COBOLMultisetLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( COBOLUserDefinedTypeLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( COBOLREFVariable );
			BOOST_SPIRIT_DEBUG_RULE( COBOLNumericType );
			BOOST_SPIRIT_DEBUG_RULE( COBOLNinesSpecification );
			BOOST_SPIRIT_DEBUG_RULE( COBOLIntegerType );
			BOOST_SPIRIT_DEBUG_RULE( COBOLBinaryInteger );
			BOOST_SPIRIT_DEBUG_RULE( COBOLNines );
			BOOST_SPIRIT_DEBUG_RULE( EmbeddedSQLFortranProgram );
			BOOST_SPIRIT_DEBUG_RULE( FortranVariableDefinition );
			BOOST_SPIRIT_DEBUG_RULE( FortranHostIdentifier );
			BOOST_SPIRIT_DEBUG_RULE( FortranTypeSpecification );
			BOOST_SPIRIT_DEBUG_RULE( FortranDerivedTypeSpecification );
			BOOST_SPIRIT_DEBUG_RULE( FortranCLOBVariable );
			BOOST_SPIRIT_DEBUG_RULE( FortranBLOBVariable );
			BOOST_SPIRIT_DEBUG_RULE( FortranUserDefinedTypeVariable );
			BOOST_SPIRIT_DEBUG_RULE( FortranCLOBLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( FortranBLOBLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( FortranUserDefinedTypeLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( FortranArrayLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( FortranMultisetLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( FortranREFVariable );
			BOOST_SPIRIT_DEBUG_RULE( EmbeddedSQLMUMPSProgram );
			BOOST_SPIRIT_DEBUG_RULE( MUMPSVariableDefinition );
			BOOST_SPIRIT_DEBUG_RULE( MUMPSCharacterVariable );
			BOOST_SPIRIT_DEBUG_RULE( MUMPSHostIdentifier );
			BOOST_SPIRIT_DEBUG_RULE( MUMPSLengthSpecification );
			BOOST_SPIRIT_DEBUG_RULE( MUMPSNumericVariable );
			BOOST_SPIRIT_DEBUG_RULE( MUMPSTypeSpecification );
			BOOST_SPIRIT_DEBUG_RULE( MUMPSDerivedTypeSpecification );
			BOOST_SPIRIT_DEBUG_RULE( MUMPSCLOBVariable );
			BOOST_SPIRIT_DEBUG_RULE( MUMPSBLOBVariable );
			BOOST_SPIRIT_DEBUG_RULE( MUMPSUserDefinedTypeVariable );
			BOOST_SPIRIT_DEBUG_RULE( MUMPSCLOBLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( MUMPSBLOBLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( MUMPSUserDefinedTypeLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( MUMPSArrayLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( MUMPSMultisetLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( MUMPSREFVariable );
			BOOST_SPIRIT_DEBUG_RULE( EmbeddedSQLPascalProgram );
			BOOST_SPIRIT_DEBUG_RULE( PascalVariableDefinition );
			BOOST_SPIRIT_DEBUG_RULE( PascalHostIdentifier );
			BOOST_SPIRIT_DEBUG_RULE( PascalTypeSpecification );
			BOOST_SPIRIT_DEBUG_RULE( PascalDerivedTypeSpecification );
			BOOST_SPIRIT_DEBUG_RULE( PascalCLOBVariable );
			BOOST_SPIRIT_DEBUG_RULE( PascalBLOBVariable );
			BOOST_SPIRIT_DEBUG_RULE( PascalCLOBLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( PascalUserDefinedTypeVariable );
			BOOST_SPIRIT_DEBUG_RULE( PascalBLOBLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( PascalUserDefinedTypeLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( PascalArrayLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( PascalMultisetLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( PascalREFVariable );
			BOOST_SPIRIT_DEBUG_RULE( EmbeddedSQLPLIProgram );
			BOOST_SPIRIT_DEBUG_RULE( PLIVariableDefinition );
			BOOST_SPIRIT_DEBUG_RULE( PLIHostIdentifier );
			BOOST_SPIRIT_DEBUG_RULE( PLITypeSpecification );
			BOOST_SPIRIT_DEBUG_RULE( PLIDerivedTypeSpecification );
			BOOST_SPIRIT_DEBUG_RULE( PLICLOBVariable );
			BOOST_SPIRIT_DEBUG_RULE( PLIBLOBVariable );
			BOOST_SPIRIT_DEBUG_RULE( PLIUserDefinedTypeVariable );
			BOOST_SPIRIT_DEBUG_RULE( PLICLOBLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( PLIBLOBLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( PLIUserDefinedTypeLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( PLIArrayLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( PLIMultisetLocatorVariable );
			BOOST_SPIRIT_DEBUG_RULE( PLIREFVariable );
			BOOST_SPIRIT_DEBUG_RULE( PLITypeFixedDecimal );
			BOOST_SPIRIT_DEBUG_RULE( PLITypeFixedBinary );
			BOOST_SPIRIT_DEBUG_RULE( PLITypeFloatBinary );
			BOOST_SPIRIT_DEBUG_RULE( DirectSQLStatement );
			BOOST_SPIRIT_DEBUG_RULE( DirectlyExecutableStatement );
			BOOST_SPIRIT_DEBUG_RULE( DirectSQLDataStatement );
			BOOST_SPIRIT_DEBUG_RULE( DirectImplementationDefinedStatement );
			BOOST_SPIRIT_DEBUG_RULE( DirectSelectStatementMultipleRows );
			BOOST_SPIRIT_DEBUG_RULE( GetDiagnosticsStatement );
			BOOST_SPIRIT_DEBUG_RULE( SQLDiagnosticsInformation );
			BOOST_SPIRIT_DEBUG_RULE( StatementInformation );
			BOOST_SPIRIT_DEBUG_RULE( StatementInformationItem );
			BOOST_SPIRIT_DEBUG_RULE( StatementInformationItemName );
			BOOST_SPIRIT_DEBUG_RULE( ConditionInformation );
			BOOST_SPIRIT_DEBUG_RULE( ConditionInformationItem );
			BOOST_SPIRIT_DEBUG_RULE( ConditionInformationItemName );
			
		rule<	ScannerT >
			SQLTerminalCharacter ,
			SQLTerminalCharacter,
			SqlSpecialCharacters ,
			Token ,
			NondelimiterToken ,
			RegularIdentifier ,
			IdentifierBody ,
			IdentifierPart ,
			IdentifierStart ,
			IdentifierExtend ,
			LargeObjectLengthToken ,
			Multiplier ,
			UnicodeDelimitedIdentifier ,
			UnicodeDelimiterBody ,
			UnicodeIdentifierPart ,
			UnicodeEscapeValue ,
			Unicode4DigitEscapeValue ,
			Unicode6DigitEscapeValue ,
			EscapeCharacter ,
			NondoublequoteCharacter ,
			DoublequoteSymbol ,
			DelimiterToken ,
			NotEqualsOperator ,
			GreaterThanOrEqualsOperator ,
			LessThanOrEqualsOperator ,
			ConcatenationOperator ,
			RightArrow ,
			DoubleColon ,
			DoublePeriod ,
			Separator ,
			Comment ,
			SimpleComment ,
			SimpleCommentIntroducer ,
			BracketedComment ,
			BracketedCommentIntroducer ,
			BracketedCommentTerminator ,
			BracketedCommentContents ,
			CommentCharacter ,
			KeyWord ,
			NonReservedWord ,
			ReservedWord ,
			Literal ,
			UnsignedLiteral ,
			GeneralLiteral ,
			CharacterStringLiteral ,
			Introducer ,
			CharacterRepresentation ,
			NonquoteCharacter ,
			QuoteSymbol ,
			NationalCharacterStringLiteral ,
			UnicodeCharacterStringLiteral ,
			UnicodeRepresentation ,
			BinaryStringLiteral ,
			SignedNumericLiteral ,
			UnsignedNumericLiteral ,
			ExactNumericLiteral ,
			ApproximateNumericLiteral ,
			Mantissa ,
			Exponent ,
			SignedInteger ,
			DatetimeLiteral ,
			DateLiteral ,
			TimeLiteral ,
			TimestampLiteral ,
			DateString ,
			TimeString ,
			TimestampString ,
			TimeZoneInterval ,
			DateValue ,
			TimeValue ,
			IntervalLiteral ,
			IntervalString ,
			UnquotedDateString ,
			UnquotedTimeString ,
			UnquotedTimestampString ,
			UnquotedIntervalString ,
			YearMonthLiteral ,
			DayTimeLiteral ,
			DayTimeInterval ,
			TimeInterval ,
			YearsValue ,
			MonthsValue ,
			DaysValue ,
			HoursValue ,
			MinutesValue ,
			SecondsValue ,
			SecondsIntegerValue ,
			SecondsFraction ,
			DatetimeValue ,
			BooleanLiteral ,
			Identifier ,
			ActualIdentifier ,
			SQLLanguageIdentifier ,
			SQLLanguageIdentifierStart ,
			SQLLanguageIdentifierPart ,
			AuthorizationIdentifier ,
			TableName ,
			DomainName ,
			SchemaName ,
			CatalogName ,
			SchemaQualifiedName ,
			LocalOrSchemaQualifiedName ,
			LocalOrSchemaQualifier ,
			QualifiedIdentifier ,
			ColumnName ,
			CorrelationName ,
			QueryName ,
			SQLClientModuleName ,
			ProcedureName ,
			SchemaQualifiedRoutineName ,
			MethodName ,
			SpecificName ,
			CursorName ,
			LocalQualifiedName ,
			LocalQualifier ,
			HostParameterName ,
			SQLParameterName ,
			ConstraintName ,
			ExternalRoutineName ,
			TriggerName ,
			CollationName ,
			CharacterSetName ,
			TransliterationName ,
			TranscodingName ,
			UserDefinedTypeName ,
			SchemaResolvedUserDefinedTypeName ,
			SchemaQualifiedTypeName ,
			AttributeName ,
			FieldName ,
			SavepointName ,
			SequenceGeneratorName ,
			RoleName ,
			UserIdentifier ,
			ConnectionName ,
			SQLServerName ,
			ConnectionUserName ,
			SQLStatementName ,
			StatementName ,
			ExtendedStatementName ,
			DynamicCursorName ,
			ExtendedCursorName ,
			DescriptorName ,
			ScopeOption ,
			WindowName ,
			DataType ,
			PredefinedType ,
			CharacterStringType ,
			NationalCharacterStringType ,
			BinaryLargeObjectStringType ,
			NumericType ,
			ExactNumericType ,
			ApproximateNumericType ,
			Length ,
			LargeObjectLength ,
			CharLengthUnits ,
			Precision ,
			Scale ,
			BooleanType ,
			DatetimeType ,
			WithOrWithoutTimeZone ,
			TimePrecision ,
			TimestampPrecision ,
			TimeFractionalSecondsPrecision ,
			IntervalType ,
			RowType ,
			RowTypeBody ,
			ReferenceType ,
			ScopeClause ,
			ReferencedType ,
			PathResolvedUserDefinedTypeName ,
			PathResolvedUserDefinedTypeName ,
			CollectionType ,
			ArrayType ,
			MultisetType ,
			FieldDefinition ,
			ValueExpressionPrimary ,
			ParenthesizedValueExpression ,
			NonparenthesizedValueExpressionPrimary ,
			ValueSpecification ,
			UnsignedValueSpecification ,
			GeneralValueSpecification ,
			SimpleValueSpecification ,
			TargetSpecification ,
			SimpleTargetSpecification ,
			HostParameterSpecification ,
			DynamicParameterSpecification ,
			EmbeddedVariableSpecification ,
			IndicatorVariable ,
			IndicatorParameter ,
			TargetArrayElementSpecification ,
			TargetArrayReference ,
			CurrentCollationSpecification ,
			ContextuallyTypedValueSpecification ,
			ImplicitlyTypedValueSpecification ,
			NullSpecification ,
			EmptySpecification ,
			DefaultSpecification ,
			IdentifierChain ,
			BasicIdentifierChain ,
			ColumnReference ,
			SQLParameterReference ,
			SetFunctionSpecification ,
			GroupingOperation ,
			WindowFunction ,
			WindowFunctionType ,
			RankFunctionType ,
			WindowNameOrSpecification ,
			InLineWindowSpecification ,
			CaseExpression ,
			CaseAbbreviation ,
			CaseSpecification ,
			SimpleCase ,
			SearchedCase ,
			SimpleWhenClause ,
			SearchedWhenClause ,
			ElseClause ,
			CaseOperand ,
			WhenOperand ,
			Result ,
			ResultExpression ,
			CastSpecification ,
			CastOperand ,
			CastTarget ,
			NextValueExpression ,
			FieldReference ,
			SubtypeTreatment ,
			SubtypeOperand ,
			TargetSubtype ,
			MethodInvocation ,
			DirectInvocation ,
			GeneralizedInvocation ,
			MethodSelection ,
			ConstructorMethodSelection ,
			StaticMethodInvocation ,
			StaticMethodSelection ,
			NewSpecification ,
			NewInvocation ,
			AttributeOrMethodReference ,
			DereferenceOperator ,
			DereferenceOperation ,
			MethodReference ,
			ReferenceResolution ,
			ArrayElementReference ,
			MultisetElementReference ,
			ValueExpression ,
			CommonValueExpression ,
			UserDefinedTypeValueExpression ,
			ReferenceValueExpression ,
			CollectionValueExpression ,
			CollectionValueConstructor ,
			NumericValueExpression ,
			Term ,
			Factor ,
			NumericPrimary ,
			NumericValueFunction ,
			PositionExpression ,
			StringPositionExpression ,
			BlobPositionExpression ,
			LengthExpression ,
			CharLengthExpression ,
			OctetLengthExpression ,
			ExtractExpression ,
			ExtractField ,
			TimeZoneField ,
			ExtractSource ,
			CardinalityExpression ,
			AbsoluteValueExpression ,
			ModulusExpression ,
			NaturalLogarithm ,
			ExponentialFunction ,
			PowerFunction ,
			NumericValueExpressionBase ,
			NumericValueExpressionExponent ,
			SquareRoot ,
			FloorFunction ,
			CeilingFunction ,
			WidthBucketFunction ,
			WidthBucketOperand ,
			WidthBucketBound1 ,
			WidthBucketBound2 ,
			WidthBucketCount ,
			StringValueExpression ,
			CharacterValueExpression ,
			Concatenation ,
			CharacterFactor ,
			CharacterPrimary ,
			BlobValueExpression ,
			BlobFactor ,
			BlobPrimary ,
			BlobConcatenation ,
			StringValueFunction ,
			CharacterValueFunction ,
			CharacterSubstringFunction ,
			RegularExpressionSubstringFunction ,
			Fold ,
			Transcoding ,
			CharacterTransliteration ,
			TrimFunction ,
			TrimOperands ,
			TrimSource ,
			TrimSpecification ,
			TrimCharacter ,
			CharacterOverlayFunction ,
			NormalizeFunction ,
			SpecificTypeMethod ,
			BlobValueFunction ,
			BlobSubstringFunction ,
			BlobTrimFunction ,
			BlobTrimOperands ,
			BlobTrimSource ,
			TrimOctet ,
			BlobOverlayFunction ,
			StartPosition ,
			StringLength ,
			DatetimeValueExpression ,
			DatetimeTerm ,
			DatetimeFactor ,
			DatetimePrimary ,
			TimeZone ,
			TimeZoneSpecifier ,
			DatetimeValueFunction ,
			CurrentDateValueFunction ,
			CurrentTimeValueFunction ,
			CurrentLocalTimeValueFunction ,
			CurrentTimestampValueFunction ,
			CurrentLocalTimestampValueFunction ,
			IntervalValueExpression ,
			IntervalTerm ,
			IntervalFactor ,
			IntervalPrimary ,
			IntervalValueExpression1 ,
			IntervalTerm1 ,
			IntervalTerm2 ,
			IntervalValueFunction ,
			IntervalAbsoluteValueFunction ,
			BooleanValueExpression ,
			BooleanTerm ,
			BooleanFactor ,
			BooleanTest ,
			TruthValue ,
			BooleanPrimary ,
			BooleanPredicand ,
			ParenthesizedBooleanValueExpression ,
			ArrayValueExpression ,
			ArrayConcatenation ,
			ArrayValueExpression1 ,
			ArrayFactor ,
			ArrayValueConstructor ,
			ArrayValueConstructorByEnumeration ,
			ArrayElementList ,
			ArrayElement ,
			ArrayValueConstructorByQuery ,
			MultisetValueExpression ,
			MultisetTerm ,
			MultisetPrimary ,
			MultisetValueFunction ,
			MultisetSetFunction ,
			MultisetValueConstructor ,
			MultisetValueConstructorByEnumeration ,
			MultisetElementList ,
			MultisetElement ,
			MultisetValueConstructorByQuery ,
			TableValueConstructorByQuery ,
			RowValueConstructor ,
			ExplicitRowValueConstructor ,
			RowValueConstructorElementList ,
			RowValueConstructorElement ,
			ContextuallyTypedRowValueConstructor ,
			ContextuallyTypedRowValueConstructorElementList ,
			ContextuallyTypedRowValueConstructorElement ,
			RowValueConstructorPredicand ,
			RowValueExpression ,
			TableRowValueExpression ,
			ContextuallyTypedRowValueExpression ,
			RowValuePredicand ,
			RowValueSpecialCase ,
			TableValueConstructor ,
			RowValueExpressionList ,
			ContextuallyTypedTableValueConstructor ,
			ContextuallyTypedRowValueExpressionList ,
			TableExpression ,
			FromClause ,
			TableReferenceList ,
			TableReference ,
			TablePrimaryOrJoinedTable ,
			SampleClause ,
			SampleMethod ,
			RepeatableClause ,
			SamplePercentage ,
			RepeatArgument ,
			TablePrimary ,
			OnlySpec ,
			LateralDerivedTable ,
			CollectionDerivedTable ,
			TableFunctionDerivedTable ,
			DerivedTable ,
			TableOrQueryName ,
			DerivedColumnList ,
			ColumnNameList ,
			JoinedTable ,
			CrossJoin ,
			QualifiedJoin ,
			NaturalJoin ,
			UnionJoin ,
			JoinSpecification ,
			JoinCondition ,
			NamedColumnsJoin ,
			JoinType ,
			OuterJoinType ,
			JoinColumnList ,
			WhereClause ,
			GroupByClause ,
			GroupingElementList ,
			GroupingElement ,
			OrdinaryGroupingSet ,
			GroupingColumnReference ,
			GroupingColumnReferenceList ,
			RollupList ,
			OrdinaryGroupingSetList ,
			CubeList ,
			GroupingSetsSpecification ,
			GroupingSetList ,
			GroupingSet ,
			EmptyGroupingSet ,
			HavingClause ,
			WindowClause ,
			WindowDefinitionList ,
			WindowDefinition ,
			NewWindowName ,
			WindowSpecification ,
			WindowSpecificationDetails ,
			ExistingWindowName ,
			WindowPartitionClause ,
			WindowPartitionColumnReferenceList ,
			WindowPartitionColumnReference ,
			WindowOrderClause ,
			WindowFrameClause ,
			WindowFrameUnits ,
			WindowFrameExtent ,
			WindowFrameStart ,
			WindowFramePreceding ,
			WindowFrameBetween ,
			WindowFrameBound1 ,
			WindowFrameBound2 ,
			WindowFrameBound ,
			WindowFrameFollowing ,
			WindowFrameExclusion ,
			QuerySpecification ,
			SelectList ,
			SelectSublist ,
			QualifiedAsterisk ,
			AsteriskedIdentifierChain ,
			AsteriskedIdentifier ,
			DerivedColumn ,
			AsClause ,
			AllFieldsReference ,
			AllFieldsColumnNameList ,
			QueryExpression ,
			WithClause ,
			WithList ,
			WithListElement ,
			WithColumnList ,
			QueryExpressionBody ,
			NonJoinQueryExpression ,
			QueryTerm ,
			NonJoinQueryTerm ,
			QueryPrimary ,
			NonJoinQueryPrimary ,
			SimpleTable ,
			ExplicitTable ,
			CorrespondingSpec ,
			CorrespondingColumnList ,
			SearchOrCycleClause ,
			SearchClause ,
			RecursiveSearchOrder ,
			SequenceColumn ,
			CycleClause ,
			CycleColumnList ,
			CycleColumn ,
			CycleMarkColumn ,
			PathColumn ,
			CycleMarkValue ,
			NonCycleMarkValue ,
			ScalarSubquery ,
			RowSubquery ,
			TableSubquery ,
			Subquery ,
			Predicate ,
			ComparisonPredicate ,
			ComparisonPredicatePart2 ,
			CompOp ,
			BetweenPredicate ,
			BetweenPredicatePart2 ,
			InPredicate ,
			InPredicatePart2 ,
			InPredicateValue ,
			InValueList ,
			LikePredicate ,
			CharacterLikePredicate ,
			CharacterLikePredicatePart2 ,
			CharacterPattern ,
			EscapeCharacter ,
			OctetLikePredicate ,
			OctetLikePredicatePart2 ,
			OctetPattern ,
			EscapeOctet ,
			SimilarPredicate ,
			SimilarPredicatePart2 ,
			SimilarPattern ,
			RegularExpression ,
			RegularTerm ,
			RegularFactor ,
			RepeatFactor ,
			UpperLimit ,
			LowValue ,
			HighValue ,
			RegularPrimary ,
			CharacterSpecifier ,
			NonEscapedCharacter ,
			EscapedCharacter ,
			RegularCharacterSet ,
			CharacterEnumerationInclude ,
			CharacterEnumerationExclude ,
			CharacterEnumeration ,
			RegularCharacterSetIdentifier ,
			NullPredicate ,
			NullPredicatePart2 ,
			QuantifiedComparisonPredicate ,
			QuantifiedComparisonPredicatePart2 ,
			Quantifier ,
			All ,
			Some ,
			ExistsPredicate ,
			UniquePredicate ,
			NormalizedPredicate ,
			MatchPredicate ,
			MatchPredicatePart2 ,
			OverlapsPredicate ,
			OverlapsPredicatePart1 ,
			OverlapsPredicatePart2 ,
			RowValuePredicand1 ,
			RowValuePredicand2 ,
			DistinctPredicate ,
			DistinctPredicatePart2 ,
			RowValuePredicand3 ,
			RowValuePredicand4 ,
			MemberPredicate ,
			MemberPredicatePart2 ,
			SubmultisetPredicate ,
			SubmultisetPredicatePart2 ,
			SetPredicate ,
			SetPredicatePart2 ,
			TypePredicate ,
			TypePredicatePart2 ,
			TypeList ,
			UserDefinedTypeSpecification ,
			InclusiveUserDefinedTypeSpecification ,
			ExclusiveUserDefinedTypeSpecification ,
			SearchCondition ,
			IntervalQualifier ,
			StartField ,
			EndField ,
			SingleDatetimeField ,
			PrimaryDatetimeField ,
			NonSecondPrimaryDatetimeField ,
			IntervalFractionalSecondsPrecision ,
			IntervalLeadingFieldPrecision ,
			LanguageClause ,
			LanguageName ,
			PathSpecification ,
			SchemaNameList ,
			RoutineInvocation ,
			RoutineName ,
			SQLArgumentList ,
			SQLArgument ,
			GeneralizedExpression ,
			CharacterSetSpecification ,
			StandardCharacterSetName ,
			ImplementationDefinedCharacterSetName ,
			UserDefinedCharacterSetName ,
			SpecificRoutineDesignator ,
			RoutineType ,
			MemberName ,
			MemberNameAlternatives ,
			DataTypeList ,
			CollateClause ,
			ConstraintNameDefinition ,
			ConstraintCharacteristics ,
			ConstraintCheckTime ,
			AggregateFunction ,
			GeneralSetFunction ,
			SetFunctionType ,
			ComputationalOperation ,
			SetQuantifier ,
			FilterClause ,
			BinarySetFunction ,
			BinarySetFunctionType ,
			DependentVariableExpression ,
			IndependentVariableExpression ,
			OrderedSetFunction ,
			HypotheticalSetFunction ,
			WithinGroupSpecification ,
			HypotheticalSetFunctionValueExpressionList ,
			InverseDistributionFunction ,
			InverseDistributionFunctionArgument ,
			InverseDistributionFunctionType ,
			SortSpecificationList ,
			SortSpecification ,
			SortKey ,
			OrderingSpecification ,
			NullOrdering ,
			SchemaDefinition ,
			SchemaCharacterSetOrPath ,
			SchemaNameClause ,
			SchemaAuthorizationIdentifier ,
			SchemaCharacterSetSpecification ,
			SchemaPathSpecification ,
			SchemaElement ,
			DropSchemaStatement ,
			DropBehavior ,
			TableDefinition ,
			TableContentsSource ,
			TableScope ,
			GlobalOrLocal ,
			TableCommitAction ,
			TableElementList ,
			TableElement ,
			SelfReferencingColumnSpecification ,
			ReferenceGeneration ,
			SelfReferencingColumnName ,
			ColumnOptions ,
			ColumnOptionList ,
			SubtableClause ,
			SupertableClause ,
			SupertableName ,
			LikeClause ,
			LikeOptions ,
			IdentityOption ,
			ColumnDefaultOption ,
			AsSubqueryClause ,
			WithOrWithoutData ,
			ColumnDefinition ,
			ColumnConstraintDefinition ,
			ColumnConstraint ,
			ReferenceScopeCheck ,
			ReferenceScopeCheckAction ,
			IdentityColumnSpecification ,
			GenerationClause ,
			GenerationRule ,
			GenerationExpression ,
			DefaultClause ,
			DefaultOption ,
			TableConstraintDefinition ,
			TableConstraint ,
			UniqueConstraintDefinition ,
			UniqueSpecification ,
			UniqueColumnList ,
			ReferentialConstraintDefinition ,
			ReferencesSpecification ,
			MatchType ,
			ReferencingColumns ,
			ReferencedTableAndColumns ,
			ReferenceColumnList ,
			ReferentialTriggeredAction ,
			UpdateRule ,
			DeleteRule ,
			ReferentialAction ,
			CheckConstraintDefinition ,
			AlterTableStatement ,
			AlterTableAction ,
			AddColumnDefinition ,
			AlterColumnDefinition ,
			AlterColumnAction ,
			SetColumnDefaultClause ,
			DropColumnDefaultClause ,
			AddColumnScopeClause ,
			DropColumnScopeClause ,
			AlterIdentityColumnSpecification ,
			AlterIdentityColumnOption ,
			DropColumnDefinition ,
			AddTableConstraintDefinition ,
			DropTableConstraintDefinition ,
			DropTableStatement ,
			ViewDefinition ,
			ViewSpecification ,
			RegularViewSpecification ,
			ReferenceableViewSpecification ,
			SubviewClause ,
			ViewElementList ,
			ViewElement ,
			ViewColumnOption ,
			LevelsClause ,
			ViewColumnList ,
			DropViewStatement ,
			DomainDefinition ,
			DomainConstraint ,
			AlterDomainStatement ,
			AlterDomainAction ,
			SetDomainDefaultClause ,
			DropDomainDefaultClause ,
			AddDomainConstraintDefinition ,
			DropDomainConstraintDefinition ,
			DropDomainStatement ,
			CharacterSetDefinition ,
			CharacterSetSource ,
			DropCharacterSetStatement ,
			CollationDefinition ,
			ExistingCollationName ,
			PadCharacteristic ,
			DropCollationStatement ,
			TransliterationDefinition ,
			SourceCharacterSetSpecification ,
			TargetCharacterSetSpecification ,
			TransliterationSource ,
			ExistingTransliterationName ,
			TransliterationRoutine ,
			DropTransliterationStatement ,
			AssertionDefinition ,
			DropAssertionStatement ,
			TriggerDefinition ,
			TriggerActionTime ,
			TriggerEvent ,
			TriggerColumnList ,
			TriggeredAction ,
			TriggeredSQLStatement ,
			OldOrNewValuesAliasList ,
			OldOrNewValuesAlias ,
			OldValuesTableAlias ,
			NewValuesTableAlias ,
			OldValuesCorrelationName ,
			NewValuesCorrelationName ,
			DropTriggerStatement ,
			UserDefinedTypeDefinition ,
			UserDefinedTypeBody ,
			UserDefinedTypeOptionList ,
			UserDefinedTypeOption ,
			SubtypeClause ,
			SupertypeName ,
			Representation ,
			MemberList ,
			Member ,
			InstantiableClause ,
			Finality ,
			ReferenceTypeSpecification ,
			UserDefinedRepresentation ,
			DerivedRepresentation ,
			SystemGeneratedRepresentation ,
			RefCastOption ,
			CastToRef ,
			CastToRefIdentifier ,
			CastToType ,
			CastToTypeIdentifier ,
			ListOfAttributes ,
			CastOption ,
			CastToDistinct ,
			CastToDistinctIdentifier ,
			CastToSource ,
			CastToSourceIdentifier ,
			MethodSpecificationList ,
			MethodSpecification ,
			OriginalMethodSpecification ,
			OverridingMethodSpecification ,
			PartialMethodSpecification ,
			SpecificMethodName ,
			MethodCharacteristics ,
			MethodCharacteristic ,
			AttributeDefinition ,
			AttributeDefault ,
			AlterTypeStatement ,
			AlterTypeAction ,
			AddAttributeDefinition ,
			DropAttributeDefinition ,
			AddOriginalMethodSpecification ,
			AddOverridingMethodSpecification ,
			DropMethodSpecification ,
			SpecificMethodSpecificationDesignator ,
			DropDataTypeStatement ,
			SQLInvokedRoutine ,
			SchemaRoutine ,
			SchemaProcedure ,
			SchemaFunction ,
			SQLInvokedProcedure ,
			SQLInvokedFunction ,
			SQLParameterDeclarationList ,
			SQLParameterDeclaration ,
			ParameterMode ,
			ParameterType ,
			LocatorIndication ,
			FunctionSpecification ,
			MethodSpecificationDesignator ,
			RoutineCharacteristics ,
			RoutineCharacteristic ,
			SavepointLevelIndication ,
			DynamicResultSetsCharacteristic ,
			ParameterStyleClause ,
			DispatchClause ,
			ReturnsClause ,
			ReturnsType ,
			ReturnsTableType ,
			TableFunctionColumnList ,
			TableFunctionColumnListElement ,
			ResultCast ,
			ResultCastFromType ,
			ReturnsDataType ,
			RoutineBody ,
			SQLRoutineSpec ,
			RightsClause ,
			SQLRoutineBody ,
			ExternalBodyReference ,
			ExternalSecurityClause ,
			ParameterStyle ,
			DeterministicCharacteristic ,
			SQLDataAccessIndication ,
			NullCallClause ,
			MaximumDynamicResultSets ,
			TransformGroupSpecification ,
			SingleGroupSpecification ,
			MultipleGroupSpecification ,
			GroupSpecification ,
			AlterRoutineStatement ,
			AlterRoutineCharacteristics ,
			AlterRoutineCharacteristic ,
			AlterRoutineBehavior ,
			DropRoutineStatement ,
			UserDefinedCastDefinition ,
			CastFunction ,
			SourceDataType ,
			TargetDataType ,
			DropUserDefinedCastStatement ,
			UserDefinedOrderingDefinition ,
			OrderingForm ,
			EqualsOrderingForm ,
			FullOrderingForm ,
			OrderingCategory ,
			RelativeCategory ,
			MapCategory ,
			StateCategory ,
			RelativeFunctionSpecification ,
			MapFunctionSpecification ,
			DropUserDefinedOrderingStatement ,
			TransformDefinition ,
			TransformGroup ,
			GroupName ,
			TransformElementList ,
			TransformElement ,
			ToSql ,
			FromSql ,
			ToSqlFunction ,
			FromSqlFunction ,
			AlterTransformStatement ,
			AlterGroup ,
			AlterTransformActionList ,
			AlterTransformAction ,
			AddTransformElementList ,
			DropTransformElementList ,
			TransformKind ,
			DropTransformStatement ,
			TransformsToBeDropped ,
			TransformGroupElement ,
			SequenceGeneratorDefinition ,
			SequenceGeneratorOptions ,
			SequenceGeneratorOption ,
			CommonSequenceGeneratorOptions ,
			CommonSequenceGeneratorOption ,
			BasicSequenceGeneratorOption ,
			SequenceGeneratorDataTypeOption ,
			SequenceGeneratorStartWithOption ,
			SequenceGeneratorStartValue ,
			SequenceGeneratorIncrementByOption ,
			SequenceGeneratorIncrement ,
			SequenceGeneratorMaxvalueOption ,
			SequenceGeneratorMaxValue ,
			SequenceGeneratorMinvalueOption ,
			SequenceGeneratorMinValue ,
			SequenceGeneratorCycleOption ,
			AlterSequenceGeneratorStatement ,
			AlterSequenceGeneratorOptions ,
			AlterSequenceGeneratorOption ,
			AlterSequenceGeneratorRestartOption ,
			SequenceGeneratorRestartValue ,
			DropSequenceGeneratorStatement ,
			GrantStatement ,
			GrantPrivilegeStatement ,
			Privileges ,
			ObjectName ,
			ObjectPrivileges ,
			Action ,
			PrivilegeMethodList ,
			PrivilegeColumnList ,
			Grantee ,
			Grantor ,
			RoleDefinition ,
			GrantRoleStatement ,
			RoleGranted ,
			DropRoleStatement ,
			RevokeStatement ,
			RevokePrivilegeStatement ,
			RevokeOptionExtension ,
			RevokeRoleStatement ,
			RoleRevoked ,
			SQLClientModuleDefinition ,
			ModuleAuthorizationClause ,
			ModuleAuthorizationIdentifier ,
			ModulePathSpecification ,
			ModuleTransformGroupSpecification ,
			ModuleCollations ,
			ModuleCollationSpecification ,
			CharacterSetSpecificationList ,
			ModuleContents ,
			ModuleNameClause ,
			ModuleCharacterSetSpecification ,
			ExternallyInvokedProcedure ,
			HostParameterDeclarationList ,
			HostParameterDeclaration ,
			HostParameterDataType ,
			StatusParameter ,
			SQLProcedureStatement ,
			SQLExecutableStatement ,
			SQLSchemaStatement ,
			SQLSchemaDefinitionStatement ,
			SQLSchemaManipulationStatement ,
			SQLDataStatement ,
			SQLDataChangeStatement ,
			SQLControlStatement ,
			SQLTransactionStatement ,
			SQLConnectionStatement ,
			SQLSessionStatement ,
			SQLDiagnosticsStatement ,
			SQLDynamicStatement ,
			SQLDynamicDataStatement ,
			SystemDescriptorStatement ,
			DeclareCursor ,
			CursorSensitivity ,
			CursorScrollability ,
			CursorHoldability ,
			CursorReturnability ,
			CursorSpecification ,
			UpdatabilityClause ,
			OrderByClause ,
			OpenStatement ,
			FetchStatement ,
			FetchOrientation ,
			FetchTargetList ,
			CloseStatement ,
			SelectStatementSingleRow ,
			SelectTargetList ,
			DeleteStatementPositioned ,
			TargetTable ,
			DeleteStatementSearched ,
			InsertStatement ,
			InsertionTarget ,
			InsertColumnsAndSource ,
			FromSubquery ,
			FromConstructor ,
			OverrideClause ,
			FromDefault ,
			InsertColumnList ,
			MergeStatement ,
			MergeCorrelationName ,
			MergeOperationSpecification ,
			MergeWhenClause ,
			MergeWhenMatchedClause ,
			MergeWhenNotMatchedClause ,
			MergeUpdateSpecification ,
			MergeInsertSpecification ,
			MergeInsertValueList ,
			MergeInsertValueElement ,
			UpdateStatementPositioned ,
			UpdateStatementSearched ,
			SetClauseList ,
			SetClause ,
			SetTarget ,
			MultipleColumnAssignment ,
			SetTargetList ,
			AssignedRow ,
			UpdateTarget ,
			ObjectColumn ,
			MutatedSetClause ,
			MutatedTarget ,
			UpdateSource ,
			TemporaryTableDeclaration ,
			FreeLocatorStatement ,
			LocatorReference ,
			HoldLocatorStatement ,
			CallStatement ,
			ReturnStatement ,
			ReturnValue ,
			StartTransactionStatement ,
			TransactionMode ,
			TransactionAccessMode ,
			IsolationLevel ,
			LevelOfIsolation ,
			DiagnosticsSize ,
			NumberOfConditions ,
			SetTransactionStatement ,
			TransactionCharacteristics ,
			SetConstraintsModeStatement ,
			ConstraintNameList ,
			SavepointStatement ,
			SavepointSpecifier ,
			ReleaseSavepointStatement ,
			CommitStatement ,
			RollbackStatement ,
			SavepointClause ,
			ConnectStatement ,
			ConnectionTarget ,
			SetConnectionStatement ,
			ConnectionObject ,
			DisconnectStatement ,
			DisconnectObject ,
			SetSessionCharacteristicsStatement ,
			SessionCharacteristicList ,
			SessionCharacteristic ,
			SetSessionUserIdentifierStatement ,
			SetRoleStatement ,
			RoleSpecification ,
			SetLocalTimeZoneStatement ,
			SetTimeZoneValue ,
			SetCatalogStatement ,
			CatalogNameCharacteristic ,
			SetSchemaStatement ,
			SchemaNameCharacteristic ,
			SetNamesStatement ,
			CharacterSetNameCharacteristic ,
			SetPathStatement ,
			SQLPathCharacteristic ,
			SetTransformGroupStatement ,
			TransformGroupCharacteristic ,
			SetSessionCollationStatement ,
			CharacterSetSpecificationList ,
			CollationSpecification ,
			AllocateDescriptorStatement ,
			Occurrences ,
			DeallocateDescriptorStatement ,
			GetDescriptorStatement ,
			GetDescriptorInformation ,
			GetHeaderInformation ,
			HeaderItemName ,
			GetItemInformation ,
			ItemNumber ,
			SimpleTargetSpecification1 ,
			SimpleTargetSpecification2 ,
			DescriptorItemName ,
			SetDescriptorStatement ,
			SetDescriptorInformation ,
			SetHeaderInformation ,
			SetItemInformation ,
			SimpleValueSpecification1 ,
			SimpleValueSpecification2 ,
			ItemNumber ,
			PrepareStatement ,
			AttributesSpecification ,
			AttributesVariable ,
			SQLStatementVariable ,
			PreparableStatement ,
			PreparableSQLDataStatement ,
			PreparableSQLSchemaStatement ,
			PreparableSQLTransactionStatement ,
			PreparableSQLControlStatement ,
			PreparableSQLSessionStatement ,
			DynamicSelectStatement ,
			PreparableImplementationDefinedStatement ,
			CursorAttributes ,
			CursorAttribute ,
			DeallocatePreparedStatement ,
			DescribeStatement ,
			DescribeInputStatement ,
			DescribeOutputStatement ,
			NestingOption ,
			UsingDescriptor ,
			DescribedObject ,
			InputUsingClause ,
			UsingArguments ,
			UsingArgument ,
			UsingInputDescriptor ,
			OutputUsingClause ,
			IntoArguments ,
			IntoArgument ,
			IntoDescriptor ,
			ExecuteStatement ,
			ResultUsingClause ,
			ParameterUsingClause ,
			ExecuteImmediateStatement ,
			DynamicDeclareCursor ,
			AllocateCursorStatement ,
			CursorIntent ,
			StatementCursor ,
			ResultSetCursor ,
			DynamicOpenStatement ,
			DynamicFetchStatement ,
			DynamicSingleRowSelectStatement ,
			DynamicCloseStatement ,
			DynamicDeleteStatementPositioned ,
			DynamicUpdateStatementPositioned ,
			PreparableDynamicDeleteStatementPositioned ,
			PreparableDynamicUpdateStatementPositioned ,
			EmbeddedSQLHostProgram ,
			EmbeddedSQLStatement ,
			StatementOrDeclaration ,
			SQLPrefix ,
			SQLTerminator ,
			EmbeddedAuthorizationDeclaration ,
			EmbeddedAuthorizationClause ,
			EmbeddedAuthorizationIdentifier ,
			EmbeddedPathSpecification ,
			EmbeddedTransformGroupSpecification ,
			EmbeddedCollationSpecification ,
			EmbeddedSQLDeclareSection ,
			EmbeddedCharacterSetDeclaration ,
			EmbeddedSQLBeginDeclare ,
			EmbeddedSQLEndDeclare ,
			EmbeddedSQLMUMPSDeclare ,
			HostVariableDefinition ,
			EmbeddedVariableName ,
			HostIdentifier ,
			EmbeddedExceptionDeclaration ,
			Condition ,
			SQLCondition ,
			MajorCategory ,
			SQLSTATEClassValue ,
			SQLSTATESubclassValue ,
			SQLSTATEChar ,
			ConditionAction ,
			GoTo ,
			GotoTarget ,
			HostLabelIdentifier ,
			HostPLILabelVariable ,
			EmbeddedSQLAdaProgram ,
			AdaVariableDefinition ,
			AdaInitialValue ,
			AdaAssignmentOperator ,
			AdaHostIdentifier ,
			AdaTypeSpecification ,
			AdaQualifiedTypeSpecification ,
			AdaUnqualifiedTypeSpecification ,
			AdaDerivedTypeSpecification ,
			AdaCLOBVariable ,
			AdaCLOBLocatorVariable ,
			AdaBLOBVariable ,
			AdaBLOBLocatorVariable ,
			AdaUserDefinedTypeVariable ,
			AdaUserDefinedTypeLocatorVariable ,
			AdaREFVariable ,
			AdaArrayLocatorVariable ,
			AdaMultisetLocatorVariable ,
			EmbeddedSQLCProgram ,
			CVariableDefinition ,
			CVariableSpecification ,
			CStorageClass ,
			CClassModifier ,
			CNumericVariable ,
			CCharacterVariable ,
			CCharacterType ,
			CArraySpecification ,
			CHostIdentifier ,
			CDerivedVariable ,
			CVARCHARVariable ,
			CNCHARVariable ,
			CNCHARVARYINGVariable ,
			CCLOBVariable ,
			CNCLOBVariable ,
			CUserDefinedTypeVariable ,
			CBLOBVariable ,
			CCLOBLocatorVariable ,
			CBLOBLocatorVariable ,
			CArrayLocatorVariable ,
			CMultisetLocatorVariable ,
			CUserDefinedTypeLocatorVariable ,
			CREFVariable ,
			CInitialValue ,
			EmbeddedSQLCOBOLProgram ,
			COBOLVariableDefinition ,
			COBOLHostIdentifier ,
			COBOLTypeSpecification ,
			COBOLDerivedTypeSpecification ,
			COBOLCharacterType ,
			COBOLNationalCharacterType ,
			COBOLCLOBVariable ,
			COBOLNCLOBVariable ,
			COBOLBLOBVariable ,
			COBOLUserDefinedTypeVariable ,
			COBOLCLOBLocatorVariable ,
			COBOLBLOBLocatorVariable ,
			COBOLArrayLocatorVariable ,
			COBOLMultisetLocatorVariable ,
			COBOLUserDefinedTypeLocatorVariable ,
			COBOLREFVariable ,
			COBOLNumericType ,
			COBOLNinesSpecification ,
			COBOLIntegerType ,
			COBOLBinaryInteger ,
			COBOLNines ,
			EmbeddedSQLFortranProgram ,
			FortranVariableDefinition ,
			FortranHostIdentifier ,
			FortranTypeSpecification ,
			FortranDerivedTypeSpecification ,
			FortranCLOBVariable ,
			FortranBLOBVariable ,
			FortranUserDefinedTypeVariable ,
			FortranCLOBLocatorVariable ,
			FortranBLOBLocatorVariable ,
			FortranUserDefinedTypeLocatorVariable ,
			FortranArrayLocatorVariable ,
			FortranMultisetLocatorVariable ,
			FortranREFVariable ,
			EmbeddedSQLMUMPSProgram ,
			MUMPSVariableDefinition ,
			MUMPSCharacterVariable ,
			MUMPSHostIdentifier ,
			MUMPSLengthSpecification ,
			MUMPSNumericVariable ,
			MUMPSTypeSpecification ,
			MUMPSDerivedTypeSpecification ,
			MUMPSCLOBVariable ,
			MUMPSBLOBVariable ,
			MUMPSUserDefinedTypeVariable ,
			MUMPSCLOBLocatorVariable ,
			MUMPSBLOBLocatorVariable ,
			MUMPSUserDefinedTypeLocatorVariable ,
			MUMPSArrayLocatorVariable ,
			MUMPSMultisetLocatorVariable ,
			MUMPSREFVariable ,
			EmbeddedSQLPascalProgram ,
			PascalVariableDefinition ,
			PascalHostIdentifier ,
			PascalTypeSpecification ,
			PascalDerivedTypeSpecification ,
			PascalCLOBVariable ,
			PascalBLOBVariable ,
			PascalCLOBLocatorVariable ,
			PascalUserDefinedTypeVariable ,
			PascalBLOBLocatorVariable ,
			PascalUserDefinedTypeLocatorVariable ,
			PascalArrayLocatorVariable ,
			PascalMultisetLocatorVariable ,
			PascalREFVariable ,
			EmbeddedSQLPLIProgram ,
			PLIVariableDefinition ,
			PLIHostIdentifier ,
			PLITypeSpecification ,
			PLIDerivedTypeSpecification ,
			PLICLOBVariable ,
			PLIBLOBVariable ,
			PLIUserDefinedTypeVariable ,
			PLICLOBLocatorVariable ,
			PLIBLOBLocatorVariable ,
			PLIUserDefinedTypeLocatorVariable ,
			PLIArrayLocatorVariable ,
			PLIMultisetLocatorVariable ,
			PLIREFVariable ,
			PLITypeFixedDecimal ,
			PLITypeFixedBinary ,
			PLITypeFloatBinary ,
			DirectSQLStatement ,
			DirectlyExecutableStatement ,
			DirectSQLDataStatement ,
			DirectImplementationDefinedStatement ,
			DirectSelectStatementMultipleRows ,
			GetDiagnosticsStatement ,
			SQLDiagnosticsInformation ,
			StatementInformation ,
			StatementInformationItem ,
			StatementInformationItemName ,
			ConditionInformation ,
			ConditionInformationItem ,
			ConditionInformationItemName 
			;
			rule<ScannerT> const& start() const
			{
				return Query;
			}
			
		}
	}
	
}
 
