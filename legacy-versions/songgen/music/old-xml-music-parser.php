<?php

if(isset($_GET['p']) == 1) {
    if ($_GET['p'] == 1) {
        echo "1VBass";
   }
    if ($_GET['p'] == 2) {
        echo "1VMelody";
    }
    if ($_GET['p'] == 3) {
        echo "1VLead";
    }
    if ($_GET['p'] == 4) {
        echo "2VBass";
    }
    if ($_GET['p'] == 5) {
        echo "2VMelody";
    }
    if ($_GET['p'] == 6) {
        echo "2VLead";
    }
    if ($_GET['p'] == 7) {
        echo "3VBass";
    }
    if ($_GET['p'] == 8) {
        echo "3VMelody";
    }
    if ($_GET['p'] == 9) {
        echo "3VLead";
    }
    if ($_GET['p'] == 10) {
        echo "BBass";
    }
    if ($_GET['p'] == 11) {
        echo "BMelody";
    }
    if ($_GET['p'] == 12) {
        echo "BLead";
    }
    if ($_GET['p'] == 13) {
        echo "CBass";
    }
    if ($_GET['p'] == 14) {
        echo "CMelody";
    }
    if ($_GET['p'] == 15) {
        echo "CLead";
    }
}

?>

<form action="<?php echo $_SERVER['SCRIPT_NAME']; ?>" method="post">
    Write to file?
    <br />
    <input type="hidden" name="submitforwrite" value="Yes" />
    <input type="submit" name="submit" value="Write" />

<h1>MusicXML Composition Generator</h1>
<h2>Presets</h2>
<table border="1">
<tr>
<th>#</th>
<th>name</th>
<th>meausres</th>
<th>speed</th>
<th>Oct Sta</th>
<th>Oct End</th>
</tr>
<tr><td>01</td> <td><a href="?p=1" title="1VBass">1VBass</a></td>       <td>16</td>       <td>1/8</td>   <td>2</td>        <td>2</td></tr>
<tr><td>02</td> <td><a href="?p=2" title="1VMelody">1VMelody</a></td>     <td>16</td>       <td>1/8</td>   <td>3</td>        <td>4</td></tr>
<tr><td>03</td> <td><a href="?p=3" title="1VLead">1VLead</a></td>       <td>16</td>       <td>1/8</td>   <td>5</td>        <td>6</td></tr>
<tr><td>04</td> <td><a href="?p=4" title="2VBass">2VBass</a></td>       <td>15</td>       <td>1/8</td>   <td>2</td>        <td>2</td></tr>
<tr><td>05</td> <td><a href="?p=5" title="2VMelody">2VMelody</a></td>     <td>15</td>       <td>1/8</td>   <td>3</td>        <td>4</td></tr>
<tr><td>06</td> <td><a href="?p=6" title="2VLead">2VLead</a></td>       <td>15</td>       <td>1/8</td>   <td>5</td>        <td>6</td></tr>
<tr><td>07</td> <td><a href="?p=7" title="3VBass">3VBass</a></td>       <td>15</td>       <td>1/8</td>   <td>2</td>        <td>2</td></tr>
<tr><td>08</td> <td><a href="?p=8" title="3VMelody">3VMelody</a></td>     <td>15</td>       <td>1/8</td>   <td>3</td>        <td>4</td></tr>
<tr><td>09</td> <td><a href="?p=9" title="3VLead">3VLead</a></td>       <td>15</td>       <td>1/8</td>   <td>5</td>        <td>6</td></tr>
<tr><td>10</td> <td><a href="?p=10" title="BBass">BBass</a></td>        <td>08</td>       <td>1/4</td>   <td>2</td>        <td>2</td></tr>
<tr><td>11</td> <td><a href="?p=11" title="BMelody">BMelody</a></td>      <td>08</td>       <td>1/4</td>   <td>3</td>        <td>4</td></tr>
<tr><td>12</td> <td><a href="?p=12" title="BLead">BLead</a></td>        <td>08</td>       <td>1/4</td>   <td>5</td>        <td>6</td></tr>
<tr><td>13</td> <td><a href="?p=13" title="CBass">CBass</a></td>        <td>07</td>       <td>1/16</td>  <td>2</td>        <td>2</td></tr>
<tr><td>14</td> <td><a href="?p=14" title="CMelody">CMelody</a></td>      <td>07</td>       <td>1/16</td>  <td>3</td>        <td>4</td></tr>
<tr><td>15</td> <td><a href="?p=15" title="CLead">CLead</a></td>        <td>07</td>       <td>1/16</td>  <td>5</td>        <td>6</td></tr>
</table>

<?php
//if((isset($_GET['p']) == 0) AND (isset($_GET['title']) == 0)) {
//        $_POST['title'] = "Default";
//        $_POST['measure'] = 1;
//        $_POST['type'] = 4;
//        $_POST['octavestart'] = 1;
//        $_POST['octaveend'] = 1;
//}
if(isset($_GET['p']) == 1) {
    if ($_GET['p'] == 1) {
        $_POST['title'] = "1VBass";
        $_POST['measure'] = 16;
        $_POST['type'] = 8;
        $_POST['octavestart'] = 2;
        $_POST['octaveend'] = 2;
    }
    if ($_GET['p'] == 2) {
        $_POST['title'] = "1VMelody";
        $_POST['measure'] = 16;
        $_POST['type'] = 8;
        $_POST['octavestart'] = 3;
        $_POST['octaveend'] = 4;
    }
    if ($_GET['p'] == 3) {
        $_POST['title'] = "1VLead";
        $_POST['measure'] = 16;
        $_POST['type'] = 8;
        $_POST['octavestart'] = 5;
        $_POST['octaveend'] = 6;
    }
    if ($_GET['p'] == 4) {
        $_POST['title'] = "2VBass";
        $_POST['measure'] = 15;
        $_POST['type'] = 8;
        $_POST['octavestart'] = 2;
        $_POST['octaveend'] = 2;
    }
    if ($_GET['p'] == 5) {
        $_POST['title'] = "2VMelody";
        $_POST['measure'] = 15;
        $_POST['type'] = 8;
        $_POST['octavestart'] = 3;
        $_POST['octaveend'] = 4;
    }
    if ($_GET['p'] == 6) {
        $_POST['title'] = "2VLead";
        $_POST['measure'] = 15;
        $_POST['type'] = 8;
        $_POST['octavestart'] = 3;
        $_POST['octaveend'] = 4;
    }
    if ($_GET['p'] == 7) {
        $_POST['title'] = "3VBass";
        $_POST['measure'] = 15;
        $_POST['type'] = 8;
        $_POST['octavestart'] = 5;
        $_POST['octaveend'] = 6;
    }
    if ($_GET['p'] == 8) {
        $_POST['title'] = "3VMelody";
        $_POST['measure'] = 15;
        $_POST['type'] = 8;
        $_POST['octavestart'] = 3;
        $_POST['octaveend'] = 4;
    }
    if ($_GET['p'] == 9) {
        $_POST['title'] = "3VLead";
        $_POST['measure'] = 15;
        $_POST['type'] = 8;
        $_POST['octavestart'] = 5;
        $_POST['octaveend'] = 6;
    }
    if ($_GET['p'] == 10) {
        $_POST['title'] = "BBass";
        $_POST['measure'] = 8;
        $_POST['type'] = 4;
        $_POST['octavestart'] = 2;
        $_POST['octaveend'] = 2;
    }
    if ($_GET['p'] == 11) {
        $_POST['title'] = "BMelody";
        $_POST['measure'] = 8;
        $_POST['type'] = 4;
        $_POST['octavestart'] = 3;
        $_POST['octaveend'] = 4;
    }
    if ($_GET['p'] == 12) {
        $_POST['title'] = "BLead";
        $_POST['measure'] = 8;
        $_POST['type'] = 4;
        $_POST['octavestart'] = 5;
        $_POST['octaveend'] = 6;
    }
    if ($_GET['p'] == 13) {
        $_POST['title'] = "CBass";
        $_POST['measure'] = 7;
        $_POST['type'] = 16;
        $_POST['octavestart'] = 2;
        $_POST['octaveend'] = 2;
    }
    if ($_GET['p'] == 14) {
        $_POST['title'] = "CMelody";
        $_POST['measure'] = 7;
        $_POST['type'] = 16;
        $_POST['octavestart'] = 3;
        $_POST['octaveend'] = 4;
    }
    if ($_GET['p'] == 15) {
        $_POST['title'] = "CLead";
        $_POST['measure'] = 7;
        $_POST['type'] = 16;
        $_POST['octavestart'] = 5;
        $_POST['octaveend'] = 6;
    }
}
?>

<h2>Custom</h2>
    Title:
    <input type="text" name="title" value="<?php if(isset($_POST['title']) == 1) {echo $_POST['title'];} ?>" />
    Measure:
    <select name="measure">
        <option <?php if(isset($_POST['measure']) == 1 AND $_POST['measure'] == 1) {echo 'selected="selected"';} ?>>1</option>
        <option <?php if(isset($_POST['measure']) == 1 AND $_POST['measure'] == 2) {echo 'selected="selected"';} ?>>2</option>
        <option <?php if(isset($_POST['measure']) == 1 AND $_POST['measure'] == 3) {echo 'selected="selected"';} ?>>3</option>
        <option <?php if(isset($_POST['measure']) == 1 AND $_POST['measure'] == 4) {echo 'selected="selected"';} ?>>4</option>
        <option <?php if(isset($_POST['measure']) == 1 AND $_POST['measure'] == 5) {echo 'selected="selected"';} ?>>5</option>
        <option <?php if(isset($_POST['measure']) == 1 AND $_POST['measure'] == 6) {echo 'selected="selected"';} ?>>6</option>
        <option <?php if(isset($_POST['measure']) == 1 AND $_POST['measure'] == 7) {echo 'selected="selected"';} ?>>7</option>
        <option <?php if(isset($_POST['measure']) == 1 AND $_POST['measure'] == 8) {echo 'selected="selected"';} ?>>8</option>
        <option <?php if(isset($_POST['measure']) == 1 AND $_POST['measure'] == 9) {echo 'selected="selected"';} ?>>9</option>
        <option <?php if(isset($_POST['measure']) == 1 AND $_POST['measure'] == 10) {echo 'selected="selected"';} ?>>10</option>
        <option <?php if(isset($_POST['measure']) == 1 AND $_POST['measure'] == 11) {echo 'selected="selected"';} ?>>11</option>
        <option <?php if(isset($_POST['measure']) == 1 AND $_POST['measure'] == 12) {echo 'selected="selected"';} ?>>12</option>
        <option <?php if(isset($_POST['measure']) == 1 AND $_POST['measure'] == 13) {echo 'selected="selected"';} ?>>13</option>
        <option <?php if(isset($_POST['measure']) == 1 AND $_POST['measure'] == 14) {echo 'selected="selected"';} ?>>14</option>
        <option <?php if(isset($_POST['measure']) == 1 AND $_POST['measure'] == 15) {echo 'selected="selected"';} ?>>15</option>
        <option <?php if(isset($_POST['measure']) == 1 AND $_POST['measure'] == 16) {echo 'selected="selected"';} ?>>16</option>
    </select>
    Octave Start:
    <select name="octavestart">
        <option <?php if(isset($_POST['octavestart']) == 1 AND $_POST['octavestart'] == 1) {echo 'selected="selected"';} ?>>1</option>
        <option <?php if(isset($_POST['octavestart']) == 1 AND $_POST['octavestart'] == 2) {echo 'selected="selected"';} ?>>2</option>
        <option <?php if(isset($_POST['octavestart']) == 1 AND $_POST['octavestart'] == 3) {echo 'selected="selected"';} ?>>3</option>
        <option <?php if(isset($_POST['octavestart']) == 1 AND $_POST['octavestart'] == 4) {echo 'selected="selected"';} ?>>4</option>
        <option <?php if(isset($_POST['octavestart']) == 1 AND $_POST['octavestart'] == 5) {echo 'selected="selected"';} ?>>5</option>
        <option <?php if(isset($_POST['octavestart']) == 1 AND $_POST['octavestart'] == 6) {echo 'selected="selected"';} ?>>6</option>
        <option <?php if(isset($_POST['octavestart']) == 1 AND $_POST['octavestart'] == 7) {echo 'selected="selected"';} ?>>7</option>
        <option <?php if(isset($_POST['octavestart']) == 1 AND $_POST['octavestart'] == 8) {echo 'selected="selected"';} ?>>8</option>
    </select>
    Octave End:
    <select name="octaveend">
        <option <?php if(isset($_POST['octaveend']) == 1 AND $_POST['octaveend'] == 1) {echo 'selected="selected"';} ?>>1</option>
        <option <?php if(isset($_POST['octaveend']) == 1 AND $_POST['octaveend'] == 2) {echo 'selected="selected"';} ?>>2</option>
        <option <?php if(isset($_POST['octaveend']) == 1 AND $_POST['octaveend'] == 3) {echo 'selected="selected"';} ?>>3</option>
        <option <?php if(isset($_POST['octaveend']) == 1 AND $_POST['octaveend'] == 4) {echo 'selected="selected"';} ?>>4</option>
        <option <?php if(isset($_POST['octaveend']) == 1 AND $_POST['octaveend'] == 5) {echo 'selected="selected"';} ?>>5</option>
        <option <?php if(isset($_POST['octaveend']) == 1 AND $_POST['octaveend'] == 6) {echo 'selected="selected"';} ?>>6</option>
        <option <?php if(isset($_POST['octaveend']) == 1 AND $_POST['octaveend'] == 7) {echo 'selected="selected"';} ?>>7</option>
        <option <?php if(isset($_POST['octaveend']) == 1 AND $_POST['octaveend'] == 8) {echo 'selected="selected"';} ?>>8</option>
    </select>
    Note Type:
    <select name="type">
        <option value="4" <?php if(isset($_POST['type']) == 1 AND $_POST['type'] == 4) {echo 'selected="selected"';} ?>>quarter</option>
        <option value="8" <?php if(isset($_POST['type']) == 1 AND $_POST['type'] == 8) {echo 'selected="selected"';} ?>>eigth</option>
        <option value="16" <?php if(isset($_POST['type']) == 1 AND $_POST['type'] == 16) {echo 'selected="selected"';} ?>>sixteenth</option>
    </select>
    <br />
    <input type="submit" name="submit" value="Generate Part" />

<h2>MusicXML</h2>
<?php

if(isset($_POST['measure']) == 1) {
    $nummeasures = $_POST['measure'];
}
if(isset($_POST['octavestart']) == 1) {
    $octlow = $_POST['octavestart'];
}
if(isset($_POST['octaveend']) == 1) {
    $octhigh = $_POST['octaveend'];
}
if(isset($_POST['type']) == 1) {
    $numnotes = $_POST['type'];
}
if(isset($_POST['title']) == 1) {
    $xmltitle = $_POST['title'];
}





$xmlfile = <<<XML
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE score-partwise PUBLIC "-//Recordare//DTD MusicXML 2.0 Partwise//EN" "http://www.musicxml.org/dtds/partwise.dtd">
<score-partwise>
  <identification>
    <encoding>
      <software>MuseScore 0.9.4</software>
      <encoding-date>2009-02-09</encoding-date>
      </encoding>
    </identification>
  <part-list>
    <score-part id="P1">
      <part-name>Piano</part-name>
      <score-instrument id="P1-I3">
        <instrument-name>Piano</instrument-name>
        </score-instrument>
      <midi-instrument id="P1-I3">
        <midi-channel>1</midi-channel>
        <midi-program>1</midi-program>
        </midi-instrument>
      </score-part>
    </part-list>
  <part id="P1">
XML;

// Measure
// Dynamics
// Step
// Octave
// type

for ($a=1; $a <= $nummeasures; $a++)
{
    $measattrib = '<measure number="' . $a . '">';
    $xmlfile = $xmlfile . $measattrib;

$xmlfile = $xmlfile . <<<XML
      <attributes>
        <divisions>480</divisions>
        <key>
          <fifths>0</fifths>
          <mode>major</mode>
          </key>
        <time>
          <beats>4</beats>
          <beat-type>4</beat-type>
          </time>
        <staves>2</staves>
        <clef number="1">
          <sign>G</sign>
          <line>2</line>
          </clef>
        <clef number="2">
          <sign>F</sign>
          <line>4</line>
          </clef>
        </attributes>
XML;

    for ($b=1; $b <= $numnotes; $b++)
    {
        // Determine the note
        $thenote = rand(1, 12);
        switch ($thenote)
        {
        case 1:
        $thenote = "C";
        break;
        case 2:
        $thenote = "C";
        $alternote = "1";
        break;
        case 3:
        $thenote = "D";
        break;
        case 4:
        $thenote = "D";
        $alternote = "1";
        break;
        case 5:
        $thenote = "E";
        break;
        case 6:
        $thenote = "F";
        break;
        case 7:
        $thenote = "F";
        $alternote = "1";
        break;
        case 8:
        $thenote = "G";
        break;
        case 9:
        $thenote = "G";
        $alternote = "1";
        break;
        case 10:
        $thenote = "A";
        break;
        case 11:
        $thenote = "A";
        $alternote = "1";
        break;
        case 12:
        $thenote = "B";
        break;
        }
        $stepattrib = '<step>' . $thenote . '</step>';
        if (isset($alternote)) {
            $alterattrib = '<alter>' . $alternote . '</alter>';
        }

        // Determine the octave
        $theoctave = rand($octlow, $octhigh);
        $octaveattrib = '<octave>' . $theoctave . '</octave>';

        // Determine the note type
        switch ($numnotes)
        {
            case 4:
            $typeattrib = "quarter";
            $durationattrib = "480";
            break;
            case 8:
            $typeattrib = "eighth";
            $durationattrib = "240";
            break;
            case 16:
            $typeattrib = "16th";
            $durationattrib = "120";
            break;
        }
        $typeattrib = '<type>' . $typeattrib . '</type>';
        $durationattrib = '<duration>' . $durationattrib . '</duration>';

        // Determine the dynamics
        if (($b == 1) OR ($b == 5) OR ($b == 9) OR ($b == 13)) {
            $dynamicsattrib = '
            <dynamics>
                <fff/>
            </dynamics>
            ';
        } elseif (($b == 2) OR ($b == 6) OR ($b == 10) OR ($b == 14)) {
            $dynamicsattrib = '
            <dynamics>
                <mp/>
            </dynamics>
            ';
        } elseif (($b == 3) OR ($b == 7) OR ($b == 11) OR ($b == 15)) {
            $dynamicsattrib = '
            <dynamics>
                <f/>
            </dynamics>
            ';
        } elseif (($b == 3) OR ($b == 8) OR ($b == 12) OR ($b == 16)) {
            $dynamicsattrib = '
            <dynamics>
                <mp/>
            </dynamics>
            ';
        }
$xmlfile = $xmlfile . <<<XML
    <direction placement="above">
        <direction-type>
XML;
$xmlfile = $xmlfile . $dynamicsattrib;
$xmlfile = $xmlfile . <<<XML
        </direction-type>
        <staff>1</staff>
    </direction>
    <note>
        <pitch>
XML;
$xmlfile = $xmlfile . $stepattrib;
if (isset($alternote)) {
    $xmlfile = $xmlfile . $alterattrib;
}
$xmlfile = $xmlfile . $octaveattrib;
$xmlfile = $xmlfile . <<<XML
        </pitch>
XML;

$xmlfile = $xmlfile . $durationattrib;

$xmlfile = $xmlfile . <<<XML
        <voice>1</voice>
XML;

$xmlfile = $xmlfile . $typeattrib;

$xmlfile = $xmlfile . <<<XML
    <stem>up</stem>
    <staff>1</staff>
  </note>
XML;
    }
$xmlfile = $xmlfile . <<<XML
      <barline location="right">
        <bar-style>light-heavy</bar-style>
        </barline>
      </measure>
XML;
}

$xmlfile = $xmlfile . <<<XML
</part>
</score-partwise>
XML;

//echo "<pre>";
//var_dump($xmlfile);
//echo "</pre>";
$xmlfile = simplexml_load_string($xmlfile);
echo '<hr /><h2>' . $xmltitle . '.xml<h2><textarea cols="50" rows="20">';
echo $xmlfile->asXML();
echo '</textarea><hr />';

if (isset($_POST['submitforwrite']) == 0)
{
    $_POST['submitforwrite'] = "No";
}

?>
</form>

<?php
if ($_POST['submitforwrite'] == "Yes") {
    $ourFileName = $_POST['title'] . ".xml";
    $ourFileHandle = fopen($ourFileName, 'w') or die("can't open file");
    fclose($ourFileHandle);

    $myFile = $_POST['title'] . ".xml";
    $fh = fopen($myFile, 'w') or die("can't open file");
    $stringData = $xmlfile->asXML();
    fwrite($fh, $stringData);
    fclose($fh);
}
?>